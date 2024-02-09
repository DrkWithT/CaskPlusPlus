/**
 * @file expr_access.cpp
 * @author DrkWithT
 * @brief Implements lvalue expression.
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "syntax/ast/expr_access.hpp"

using namespace cask::syntax;

AccessExpr::AccessExpr(std::any source_value, std::any key_str)
: source (std::move(source_value)), keys {}
{}

const std::any& AccessExpr::getSource() const
{
    return source;
}

const std::vector<std::any>& AccessExpr::getKeys() const
{
    return keys;
}

void AccessExpr::addAttributeKey(const std::any& attr_key)
{
    keys.emplace_back(attr_key);
}

void AccessExpr::acceptVisitor(IExprVisitor& visitor) const
{
    visitor.visitAccessExpr(*this);
}
