#ifndef CASK_EXPR_VISITOR_HPP
#define CASK_EXPR_VISITOR_HPP

namespace cask::syntax
{
    /* Forward declare visitable classes... */
    /// @note: use std::any for any primitive literal value, etc.
    class LiteralExpr;
    class AccessExpr;
    class CallExpr;
    class TermExpr;
    class FactorExpr;
    class ModuloExpr;
    class ComparisonExpr;
    class EqualityExpr;
    class ConditionalExpr;

    /**
     * @brief Generic Visitor pattern interface for anything to check an AST node. This is used in concrete visitors that walk the AST to validate it or generate code!
     */
    class IExprVisitor
    {
    public:
        virtual ~IExprVisitor() {}
        virtual void visitLiteralExpr(const LiteralExpr& expr) = 0;
        virtual void visitAccessExpr(const AccessExpr& expr) = 0;
        virtual void visitCallExpr(const CallExpr& expr) = 0;
        virtual void visitTermExpr(const TermExpr& expr) = 0;
        virtual void visitFactorExpr(const FactorExpr& expr) = 0;
        virtual void visitModuloExpr(const ModuloExpr& expr) = 0;
        virtual void visitComparisonExpr(const ComparisonExpr& expr) = 0;
        virtual void visitEqualityExpr(const EqualityExpr& expr) = 0;
        virtual void visitConditionalExpr(const ConditionalExpr& expr) = 0;
    };
}

#endif