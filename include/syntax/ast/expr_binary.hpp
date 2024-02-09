#ifndef EXPR_BINARY_HPP
#define EXPR_BINARY_HPP

#include <any>
#include <utility>
#include "syntax/ast/expr_basic.hpp"

namespace cask::syntax
{
    enum BinaryOperator
    {
        op_plus,
        op_minus,
        op_multiply,
        op_divide,
        op_modulo,
        op_lt,
        op_lte,
        op_gt,
        op_gte,
        op_equality,
        op_inequality,
        op_logical_or,
        op_logical_and
    };

    /**
     * @brief AST node class for all binary expressions e.g term, factor, modulo, comparison, equality, conditional.
     */
    class BinaryExpr : public IAstExpr
    {
    private:
        std::any left;
        std::any right;
        BinaryOperator op;
    public:
        BinaryExpr(BinaryOperator op, std::any left_node, std::any right_node);

        const std::any& getLeft() const;
        const std::any& getRight() const;
        BinaryOperator getOperator() const;

        void acceptVisitor(IExprVisitor& visitor) const override;
    };
}

#endif