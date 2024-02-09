/**
 * @file expr_call.cpp
 * @author DrkWithT
 * @brief Implements function call expression.
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "syntax/ast/expr_call.hpp"

using namespace cask::syntax;

CallExpr::CallExpr(const std::string& name)
: callee_name {name}, callee_args {}
{}

const std::vector<std::any>& CallExpr::getArgs() const
{
    return callee_args;
}

const std::string& CallExpr::getName() const
{
    return callee_name;
}

void CallExpr::appendArg(std::any arg)
{
    callee_args.emplace_back(std::move(arg));
}

void CallExpr::acceptVisitor(IExprVisitor& visitor) const
{
    visitor.visitCallExpr(*this);
}
