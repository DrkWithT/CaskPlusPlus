#ifndef STMT_FUNC_HPP
#define STMT_FUNC_HPP

#include <any>
#include <string>
#include <vector>
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    class ParamStmt : public IAstStmt
    {
    private:
        std::string name;
        std::string type_name;
        bool value_flag;
    public:
        ParamStmt(std::string name, std::string type_name, bool value_flag);

        const std::string& getName() const;
        const std::string& getTypename() const;
        bool getValueFlag() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class FuncStmt : public IAstStmt
    {
    private:
        std::string name;
        std::string ret_type;
        std::vector<ParamStmt> params;
        std::vector<std::any> stmts;
    public:
        FuncStmt(std::string name, std::string ret_type);

        const std::string& getName() const;
        const std::string& getReturnType() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif