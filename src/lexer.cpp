/**
 * @file lexer.cpp
 * @author DrkWithT
 * @brief Implements tokenizer for Cask language.
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "frontend/lexer.hpp"

using namespace cask::frontend;

/* Helper Constexprs */

/// Special whitespace letters
constexpr char cask_sp = ' ';
constexpr char cask_tb = '\t';
constexpr char cask_cr = '\r';
constexpr char cask_lf = '\n';

/// Number of keywords
constexpr size_t cask_word_count = 17;

/// Number of operators
constexpr size_t cask_op_count = 13;

/// Keywords to check
constexpr char* cask_words[] {
    "from",
    "import",
    "agg",
    "func",
    "val",
    "ref",
    "let",
    "while",
    "if",
    "else",
    "end",
    "bool", // Begin primitive typenames
    "int",
    "string",
    "float",
    "true", // Begin special literals
    "false"
};

constexpr TokenType cask_word_lexical_type[] {
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_keyword,
    token_typename,
    token_typename,
    token_typename,
    token_typename,
    token_boolean,
    token_boolean
};

constexpr const char* cask_operator_literals[] {
    "=",
    "||",
    "&&",
    "==",
    "!=",
    "<",
    ">",
    "<=",
    ">=",
    "*",
    "/",
    "+",
    "-"
};

constexpr TokenType cask_operator_lexical_types[] {
    token_op_assignment,
    token_op_or,
    token_op_and,
    token_op_equality,
    token_op_inequality,
    token_op_less,
    token_op_greater,
    token_op_less_equals,
    token_op_greater_equals,
    token_op_multiply,
    token_op_divide,
    token_op_plus,
    token_op_minus
};

/* Helper Character Functions */

constexpr bool charIsAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

constexpr bool charIsNumeric(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

constexpr bool charIsOpSymbol(char c) {
    return c != '!' && c != '=' && c != '*' && c != '/' && c != '+' && c != '-' && c != '|' && c != '&';
}

constexpr bool charIsSpace(char c) {
    return (c == cask_sp || c == cask_tb || c == cask_cr || c == cask_lf);
}

/* Lexer impl. */

Lexer::Lexer(const char* source_cstr, size_t source_cstr_length)
: keywords {}, typenames {}, specials {}, operators {}, sout {}, source_view {source_cstr}, source_index {0}, source_length {source_cstr_length}
{
    for (size_t word_i = 0; word_i < cask_word_count; word_i++)
    {
        switch (cask_word_lexical_type[word_i])
        {
        case token_keyword:
            keywords.insert({cask_words[word_i]});
            break;
        case token_typename:
            typenames.insert({cask_words[word_i]});
            break;
        case token_boolean:
            specials.insert(cask_words[word_i]);
            break;
        default:
            break;
        }
    }

    for (size_t oper_i = 0; oper_i < cask_op_count; oper_i++)
    {
        operators.insert({cask_operator_literals[oper_i], cask_operator_lexical_types[oper_i]});
    }
}

void Lexer::skipWhitespace()
{
    char temp = '\0';

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        if (!charIsSpace(temp))
            break;

        source_index++;
    }
}

Token Lexer::lexSingular(TokenType type)
{
    size_t singular_start = source_index;

    source_index++;

    return (Token) {.begin = singular_start, .length = 1, .type = type};
}

Token Lexer::lexComment()
{
    source_index++;

    size_t comment_start = source_index;
    size_t comment_length = 0;
    char temp = '\0';

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        if (temp == '#')
        {
            source_index++;
            break;
        }

        source_index++;
        comment_length++;
    }
    
    return (Token) {.begin = comment_start, .length = comment_length, .type = token_comment};
}

Token Lexer::lexWord()
{
    size_t word_begin = source_index;
    size_t word_len = 0;
    char temp = '\0';

    sout.clear();

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        if (!charIsAlpha(temp))
            break;
        
        sout << temp;
        source_index++;
        word_len++;
    }

    std::string lexeme_str {sout.str()};

    if (keywords.find(lexeme_str) != keywords.end())
        return (Token) {.begin = word_begin, .length = word_len, .type = token_keyword};

    if (typenames.find(lexeme_str) != typenames.end())
        return (Token) {.begin = word_begin, .length = word_len, .type = token_typename};

    /// @note The only special literals are true, false booleans- Thus a special is always a boolean.
    if (specials.find(lexeme_str) != specials.end())
        return (Token) {.begin = word_begin, .length = word_len, .type = token_boolean};

    return (Token) {.begin = word_begin, .length = word_len, .type = token_identifier};
}

/// @todo Create an unordered_map in Lexer for defined operators to their token type...
Token Lexer::lexOperator()
{
    size_t oper_begin = source_index;
    size_t oper_length = 0;
    char temp = '\0';

    sout.clear();

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        /// @note I will stop consuming letters for this possible operator if the letters aren't valid operator symbols... Follow the assumption that a token contains similar characters for its kind.
        if (temp != '!' && temp != '=' && temp != '*' && temp != '/' && temp != '+' && temp != '-' && temp != '|' && temp != '&')
            break;

        sout << temp;

        oper_length++;
        source_index++;
    }

    std::string oper_lexeme = sout.str();

    if (operators.find(oper_lexeme) == operators.end())
        return (Token) {.begin = oper_begin, .length = oper_length, .type = token_unknown};
    
    return (Token) {
        .begin = oper_begin,
        .length = oper_length,
        .type = operators.at(oper_lexeme)
    };
}

Token Lexer::lexNumeric()
{
    size_t numeric_begin = source_index;
    size_t numeric_length = 0;
    char temp = '\0';
    int dot_count = 0;

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        if (!charIsNumeric(temp))
            break;
        
        if (temp == '.')
            dot_count++;

        numeric_length++;
        source_index++;
    }

    switch (dot_count)
    {
    case 0:
        return (Token) {.begin = numeric_begin, .length = numeric_length, .type = token_integer};
    case 1:
        return (Token) {.begin = numeric_begin, .length = numeric_length, .type = token_float};
    default:
        return (Token) {.begin = numeric_begin, .length = numeric_length, .type = token_unknown};
    }
}

Token Lexer::lexString()
{
    /// @note skip 1st closing double quote to avoid infinite scan loop!
    source_index++;

    size_t strbody_start = source_index;
    size_t strbody_length = 0;
    char temp = '\0';

    while (source_index < source_length)
    {
        temp = source_view[source_index];

        if (temp == '\"')
        {
            source_index++;
            break;
        }

        source_length++;
        source_index++;
    }

    return (Token) {.begin = strbody_start, .length = strbody_length, .type = token_string};
}

Token Lexer::lexNext()
{
    if (source_index >= source_length)
        return (Token) {.begin = source_length, .length = 1, .type = token_eof};
    
    char peek_symbol = source_view[source_index];

    if (charIsSpace(peek_symbol))
        skipWhitespace();

    peek_symbol = source_view[source_index];

    switch (peek_symbol)
    {
    case '{':
        return lexSingular(token_left_brace);
    case '}':
        return lexSingular(token_right_brace);
    case '[':
        return lexSingular(token_left_brack);
    case ']':
        return lexSingular(token_right_brack);
    case '(':
        return lexSingular(token_left_paren);
    case ')':
        return lexSingular(token_right_paren);
    default:
        break;
    }
    
    if (peek_symbol == '#')
        return lexComment();
    else if (charIsAlpha(peek_symbol))
        return lexWord();
    else if (charIsOpSymbol(peek_symbol))
        return lexOperator();

    return (Token) {.begin = source_index++, .length = 1, .type = token_unknown};
}
