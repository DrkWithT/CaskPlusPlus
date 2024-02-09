#ifndef EXPR_CALL_HPP
#define EXPR_CALL_HPP

#include <any>
#include <string>
#include <vector>
#include "syntax/ast/cask_ast_expr.hpp"

namespace cask::syntax
{
    class CallExpr : public IAstExpr
    {
    private:
        std::vector<std::any> callee_args;
        std::string callee_name;
    public:
        CallExpr(const std::string& name);

        const std::vector<std::any>& getArgs() const;
        const std::string& getName() const;

        void appendArg(std::any arg);

        void acceptVisitor(IExprVisitor& visitor) const override;
    };
}

#endif