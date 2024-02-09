#ifndef EXPR_ACCESS_HPP
#define EXPR_ACCESS_HPP

#include <any>
#include <utility>
#include <vector>
#include "syntax/ast/cask_ast_expr.hpp"

namespace cask::syntax
{
    class AccessExpr : public IAstExpr
    {
    private:
        std::any source;
        std::vector<std::any> keys;
    public:
        AccessExpr(std::any source_value, std::any key_str);

        const std::any& getSource() const;
        const std::vector<std::any>& getKeys() const;
        void addAttributeKey(const std::any& attr_key);

        void acceptVisitor(IExprVisitor& visitor) const override;
    };
}

#endif