#ifndef STMT_AGGREGATE_HPP
#define STMT_AGGREGATE_HPP

#include <string>
#include <vector>
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    class StmtAggField : public IAstStmt
    {
    private:
        std::string field_name;
        std::string field_type;
    public:
        StmtAggField(std::string name, std::string type);

        const std::string& getName() const;
        const std::string& getType() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };

    class StmtAggregate : public IAstStmt
    {
    private:
        std::vector<StmtAggField> fields;
        std::string name;
    public:
        StmtAggregate(std::string name);

        const std::vector<StmtAggField>& getFields() const;
        const std::string& getName() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif