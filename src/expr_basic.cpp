/**
 * @file expr_basic.cpp
 * @author DrkWithT
 * @brief Implements basic expression, a.k.a literal expression.
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "syntax/ast/expr_basic.hpp"

using namespace cask::syntax;

BasicExpr::BasicExpr(std::any literal_value)
: literal (std::move(literal_value))
{}

const std::any& BasicExpr::getLiteral() const
{
    return literal;
}

void BasicExpr::acceptVisitor(IExprVisitor& visitor) const
{
    visitor.visitBasicExpr(*this);
}
