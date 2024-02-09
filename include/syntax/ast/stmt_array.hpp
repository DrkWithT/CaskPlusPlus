#ifndef STMT_ARRAY_HPP
#define STMT_ARRAY_HPP

#include <any>
#include <string>
#include <vector>
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    class ArrayStmt : public IAstStmt
    {
    private:
        std::vector<std::any> items;
        std::string var_name;
    public:
        ArrayStmt(std::string var_name);

        const std::vector<std::any>& getItem() const;
        const std::string& getName() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif