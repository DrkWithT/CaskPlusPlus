#ifndef CASK_EXPR_VISITOR_HPP
#define CASK_EXPR_VISITOR_HPP

namespace cask::syntax
{
    /* Forward declare visitable classes... */
    /// @note: use std::any for any primitive literal value, etc.
    class BasicExpr;
    class AccessExpr;
    class CallExpr;
    class BinaryExpr;

    /**
     * @brief Generic Visitor pattern interface for anything to check an AST node. This is used in concrete visitors that walk the AST to validate it or generate code!
     */
    class IExprVisitor
    {
    public:
        virtual ~IExprVisitor() {}
        virtual void visitBasicExpr(const BasicExpr& expr) = 0;
        virtual void visitAccessExpr(const AccessExpr& expr) = 0;
        virtual void visitCallExpr(const CallExpr& expr) = 0;
        virtual void visitBinaryExpr(const BinaryExpr& expr) = 0;
    };
}

#endif