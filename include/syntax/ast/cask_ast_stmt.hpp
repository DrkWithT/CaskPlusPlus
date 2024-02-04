#ifndef CASK_AST_STMT_HPP
#define CASK_AST_STMT_HPP

#include "syntax/visitor/cask_stmt_visitor.hpp"

namespace cask::syntax
{
    /**
     * @brief Defines the IAstExpr interface for expressions to accept an appropriate visitor.
     */
    class IAstStmt
    {
    public:
        virtual ~IAstStmt() {}
        virtual void acceptVisitor(IStmtVisitor& visitor) const = 0;
    };
}

#endif