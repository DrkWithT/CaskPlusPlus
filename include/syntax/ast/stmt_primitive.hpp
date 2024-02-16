#ifndef STMT_PRIMITIVE
#define STMT_PRIMITIVE

#include <any>
#include "syntax/ast/cask_ast_enums.hpp"
#include "syntax/ast/cask_ast_stmt.hpp"

namespace cask::syntax
{
    class VarDeclStmt : public IAstStmt
    {
    private:
        std::any value;
        CaskDataType type;
    public:
        VarDeclStmt(CaskDataType data_type, std::any data_value);

        const std::any& getValue() const;
        CaskDataType getType() const;

        void acceptVisitor(IStmtVisitor& visitor) const override;
    };
}

#endif