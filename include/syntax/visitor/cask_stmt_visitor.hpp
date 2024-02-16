#ifndef CASK_STMT_VISITOR_HPP
#define CASK_STMT_VISITOR_HPP

namespace cask::syntax
{
    class VarDeclStmt;
    class AggFieldDeclStmt;
    class AggDeclStmt;
    class ArrDeclStmt;
    class FuncDeclStmt;
    class FuncParamStmt;
    class ImportStmt;
    class ReassignStmt;
    class WhileStmt;
    class IfStmt;
    class ElseStmt;
    class BlockStmt;

    class IStmtVisitor
    {
    public:
        ~IStmtVisitor() = default;

        virtual void visitVarDeclStmt(const VarDeclStmt& stmt) = 0;
        virtual void visitAggFieldDecl(const AggFieldDeclStmt& stmt) = 0;
        virtual void visitAggDecl(const AggDeclStmt& stmt) = 0;
        virtual void visitArrDecl(const ArrDeclStmt& stmt) = 0;
        virtual void visitFuncDecl(const FuncDeclStmt& stmt) = 0;
        virtual void visitFuncParam(const FuncParamStmt& stmt) = 0;
        virtual void visitImport(const ImportStmt& stmt) = 0;
        virtual void visitReassign(const ReassignStmt& stmt) = 0;
        virtual void visitWhile(const WhileStmt& stmt) = 0;
        virtual void visitIf(const IfStmt& stmt) = 0;
        virtual void visitElse(const ElseStmt& stmt) = 0;
        virtual void visitBlock(const BlockStmt& stmt) = 0;
    };
}

#endif