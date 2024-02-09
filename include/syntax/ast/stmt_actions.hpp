#ifndef STMT_ACTIONS_HPP
#define STMT_ACTIONS_HPP

#include <any>
#include <string>
#include "syntax/ast/expr_binary.hpp"
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    class ImportStmt : public IAstStmt
    {
    private:
        std::string source;
        std::vector<std::string> items;
    public:
        ImportStmt(std::string source_name);

        const std::string& getSource() const;
        const std::vector<std::string>& getItems() const;
        void addImportItem(const std::string& item_name);

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class ReassignStmt : public IAstStmt
    {
    private:
        std::any lvalue_expr;
        std::any rvalue_expr;
    public:
        ReassignStmt(std::any lvalue, std::any rvalue);

        const std::any& getLValue() const;
        const std::any& getRValue() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class WhileStmt : public IAstStmt
    {
    private:
        std::any conditional;
        BlockStmt block;
    public:
        WhileStmt(std::any conditions, BlockStmt stmts);

        const std::any& getConditional() const;
        const BlockStmt& getBlock() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class IfStmt : public IAstStmt
    {
    private:
        std::any conditional;
        std::any otherwise;
        BlockStmt block;
    public:
        IfStmt(std::any check_expr, std::any other_else, BlockStmt block);

        const std::any& getConditional() const;
        const std::any& getElseStmt() const;
        const BlockStmt& getIfBlock() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class ElseStmt : public IAstStmt
    {
    private:
        BlockStmt block;
    public:
        ElseStmt(BlockStmt stmts);

        const BlockStmt& getBlock() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class BlockStmt : public IAstStmt
    {
    private:
        std::vector<std::any> stmts;
    public:
        BlockStmt();

        const std::vector<std::any>& getStmts();
        void appendStmt(std::any stmt);

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif