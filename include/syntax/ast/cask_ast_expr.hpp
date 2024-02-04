#ifndef CASK_AST_EXPR_HPP
#define CASK_AST_EXPR_HPP

/// @see https://github.com/eliasdaler/lox/blob/master/include/lox/Stmt/StmtVisitor.h

#include "syntax/visitor/cask_expr_visitor.hpp"

namespace cask::syntax
{
    /**
     * @brief Defines the IAstExpr interface for expressions to accept an appropriate visitor.
     */
    class IAstExpr
    {
    public:
        virtual ~IAstExpr() {}
        virtual void acceptVisitor(IExprVisitor& visitor) const = 0;
    };
}

#endif