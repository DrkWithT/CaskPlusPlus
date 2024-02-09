#ifndef EXPR_BASIC_HPP
#define EXPR_BASIC_HPP

#include <any>
#include "syntax/ast/cask_ast_expr.hpp"

namespace cask::syntax
{
    class BasicExpr : public IAstExpr
    {
    private:
        std::any literal;
    public:
        BasicExpr(std::any literal_value);

        const std::any& getLiteral() const;

        void acceptVisitor(IExprVisitor& visitor) const override;
    };
}

#endif