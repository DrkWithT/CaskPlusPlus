# Cask Grammar

## Notes:
 - Comments are multi-line by default.
    - Delimited by `'#'`.
 - `agg` means a data structure wrapping one or more typed attributes. This will be like a C `struct`.
 - Math operators: `+, -, *, /`
 - Equality, comparison operators: `==, !=, >, >=, <, <=`
 - Logical operators : `||, &&`

### Core Grammar

```bnf
; basic elements
comment ::= "#" (ANY)* "#"
identifier ::= (ALPHA | "_")+ ; can be identifier or custom aggregate name
primtype ::= "bool" | "int" | "float" | "string"
aggtype ::= identifier
arrtype ::= (primtype | aggtype) "[" "]"
bool-literal ::= "true" | "false"
integer-literal ::= ("-"){0,1} (DIGIT)+
float-literal ::= ("-"){0,1} (DIGIT)+ "." (DIGIT)+
string-literal ::= "\"" (ALPHA)* "\""
agg-literal ::= "{" literal ("," literal)* "}"
array-literal ::= "[" (basic ",")* "]"

; expressions
basic ::= nil-literal | bool-literal | integer-literal | float-literal | string-literal | array-literal | agg-literal | identifier | call-expr | "(" equality-expr ")"
call-expr ::= identifier "(" (basic){0, 1} ("," basic)* ")"
access-expr ::= basic "[" integer-literal | string-literal | identifier "]"
term-expr ::= access-expr (("+" | "-") access-expr)+
factor-expr ::= term-expr ("*" | "/" term-expr)
comparison-expr ::= factor-expr (("<" | "<=" | ">" | ">=") factor-expr)+
equality-expr ::= comparison-expr (("==" | "!=") comparison-expr)+
conditional-expr ::= equality-expr (("||" | "&&") equality-expr)+

; declaration statements
decl ::= prim-decl | agg-decl | func-decl
prim-decl ::= "let" identifier ":" primtype "=" (nil_literal | bool_literal | integer-literal | float-literal | string-literal)
field-decl ::= identifier ":" primtype
agg-decl ::= "agg" identifier (field-decl)*+* "end"
arr-decl ::= "let" identifier ":" arrtype "=" array-literal
func-decl ::= "func" identifier "(" (param-decl)* ")" ":" (primtype | addtype | arrtype) block
param-decl ::= ("val" | "ref") identifier ":" (primtype | aggtype | arrtype)

; action statements
import-stmt ::= "from" identifier "import" "*" | (identififer ("," identifier)*)
reassign-stmt ::= access "=" conditional-expr
while-stmt ::= "while" "(" conditional-expr ")" block
if-stmt ::= "if" "(" conditional-expr ")" block (else-stmt){1}
else-stmt ::= "else" block
block ::= (stmt)+ "end"

; top program structure
program ::= (import-stmt | agg-decl | func-decl)*
```
