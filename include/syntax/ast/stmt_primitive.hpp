#ifndef STMT_PRIMITIVE
#define STMT_PRIMITIVE

#include <any>
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    enum PrimitiveType
    {
        primitive_bool,
        primitive_int,
        primitive_float,
        primitive_string
    };

    class StmtPrimitive : public IAstStmt
    {
    private:
        std::any value;
        PrimitiveType type;
    public:
        StmtPrimitive(PrimitiveType pmt_type, std::any pmt_value);

        const std::any& getValue() const;
        PrimitiveType getType() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif