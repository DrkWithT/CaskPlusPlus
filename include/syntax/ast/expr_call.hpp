#ifndef EXPR_CALL_HPP
#define EXPR_CALL_HPP

#include <any>
#include <string>
#include "syntax/ast/cask_ast_expr.hpp"

namespace cask::syntax
{
    class CallExpr : public IAstExpr
    {
    private:
        std::vector<std::any> args;
        std::string name;
    public:
        CallExpr(std::string name);

        const std::string& getName() const;
        const std::vector<std::any>& getArgs() const;

        void appendArg(std::any arg);

        void acceptVisitor(IExprVisitor& visitor) const override;
    };
}

#endif