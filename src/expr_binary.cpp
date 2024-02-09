/**
 * @file expr_binary.cpp
 * @author DrkWithT
 * @brief Implements binary expressions.
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "syntax/ast/expr_binary.hpp"

using namespace cask::syntax;

BinaryExpr::BinaryExpr(BinaryOperator op, std::any left_node, std::any right_node)
: left(std::move(left_node)), right(std::move(right_node))
{
    this->op = op;
}

const std::any& BinaryExpr::getLeft() const
{
    return left;
}

const std::any& BinaryExpr::getRight() const
{
    return right;
}

BinaryOperator BinaryExpr::getOperator() const
{
    return op;
}

void BinaryExpr::acceptVisitor(IExprVisitor& visitor) const
{
    visitor.visitBinaryExpr(*this);
}
