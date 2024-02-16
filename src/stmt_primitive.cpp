/**
 * @file stmt_primitive.cpp
 * @author DrkWithT
 * @brief Implements primitive variable declarations.
 * @date 2024-02-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "syntax/ast/stmt_primitive.hpp"

using namespace cask::syntax;

VarDeclStmt::VarDeclStmt(CaskDataType data_type, std::any data_value)
: value(std::move(data_value)), type {data_type}
{}

const std::any& VarDeclStmt::getValue() const
{
    return value;
}

CaskDataType VarDeclStmt::getType() const
{
    return type;
}

void VarDeclStmt::acceptVisitor(IStmtVisitor& visitor) const
{
    visitor.visitVarDeclStmt(*this);
}
