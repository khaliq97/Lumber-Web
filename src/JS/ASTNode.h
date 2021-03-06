#ifndef ASTNODE_H
#define ASTNODE_H
#include <JS/Value.h>
#include <memory>
class ASTNode
{
    public:
        virtual ~ASTNode();
        virtual std::shared_ptr<Value> execute() = 0;

};

class Statement : public ASTNode
{

};

class DeclarationStatement : public Statement
{

};


#endif // ASTNODE_H
