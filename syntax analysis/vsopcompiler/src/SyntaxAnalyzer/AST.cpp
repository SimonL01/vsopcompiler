#include "AST.hpp"
#include <iostream>
#include <memory>

using std::make_unique;
using std::unique_ptr;

/************************************/
/*         Vistor interface         */
/************************************/

/************************************/
/*            Expr class            */
/************************************/

template <typename T>
Expr<T>::~Expr()
{
}

/************************************/
/*            Type class            */
/************************************/

template <typename T>
Type<T>::Type(const std::string type) : type(type) {}

template <typename T>
auto Type<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Type<T>::getType() { return this->type; }

template <typename T>
Type<T>::~Type() {}

/************************************/
/*           Formal class           */
/************************************/

template <typename T>
Formal<T>::Formal(const std::string name, Type<T> type) : name(name), type(type) {}

template <typename T>
auto Formal<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Formal<T>::getName() { return this->name; }

template <typename T>
Type<T> Formal<T>::getType() { return this->type; }

template <typename T>
Formal<T>::~Formal() {}

/************************************/
/*           Block class            */
/************************************/

template <typename T>
Block<T>::Block(std::vector<Expr<T> *> *expr_list) : expr_list(expr_list) {}

template <typename T>
auto Block<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
std::vector<Expr<T> *> *Block<T>::getExpr_list() { return this->expr_list; }

template <typename T>
void Block<T>::AddExpr(Expr<T> *e) { expr_list->push_back(e); }

template <typename T>
Block<T>::~Block()
{
    for (auto b : *expr_list)
        delete b;
}

/************************************/
/*       Conditional class          */
/************************************/

template <typename T>
Conditional<T>::Conditional(Expr<T> *cond_expr, Expr<T> *then_expr, Expr<T> *else_expr)
    : cond_expr(cond_expr), then_expr(then_expr), else_expr(else_expr) {}

template <typename T>
auto Conditional<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
Expr<T> *Conditional<T>::getCond_expr() { return this->cond_expr; }

template <typename T>
Expr<T> *Conditional<T>::getThen_expr() { return this->then_expr; }

template <typename T>
Expr<T> *Conditional<T>::getElse_expr() { return this->else_expr; }

template <typename T>
Conditional<T>::~Conditional()
{
    delete cond_expr;
    delete then_expr;
    delete else_expr;
}

/************************************/
/*           While class            */
/************************************/

template <typename T>
While<T>::While(Expr<T> *cond_expr, Expr<T> *body_expr)
    : cond_expr(cond_expr), body_expr(body_expr) {}

template <typename T>
auto While<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
Expr<T> *While<T>::getCond_expr() { return this->cond_expr; }

template <typename T>
Expr<T> *While<T>::getBody_expr() { return this->body_expr; }

template <typename T>
While<T>::~While()
{
    delete cond_expr;
    delete body_expr;
}

/************************************/
/*            Let class             */
/************************************/

template <typename T>
Let<T>::Let(const std::string name, Type<T> type, Expr<T> *scope_expr, Expr<T> *init_expr)
    : name(name), type(type), init_expr(init_expr), scope_expr(scope_expr) {}

template <typename T>
auto Let<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Let<T>::getName() { return this->name; }

template <typename T>
Type<T> Let<T>::getType() { return this->type; }

template <typename T>
Expr<T> *Let<T>::getInit_expr() { return this->init_expr; }

template <typename T>
Expr<T> *Let<T>::getScope_expr() { return this->scope_expr; }

template <typename T>
Let<T>::~Let()
{
    delete scope_expr;
    delete init_expr;
}

/************************************/
/*           Assign class           */
/************************************/

template <typename T>
Assign<T>::Assign(const std::string name, Expr<T> *expr) : name(name), expr(expr) {}

template <typename T>
auto Assign<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Assign<T>::getName() { return this->name; }

template <typename T>
Expr<T> *Assign<T>::getExpr() { return this->expr; }

template <typename T>
Assign<T>::~Assign()
{
    delete expr;
}

/************************************/
/*           UnOp class             */
/************************************/

template <typename T>
UnOp<T>::UnOp(const std::string op, Expr<T> *expr) : op(op), expr(expr) {}

template <typename T>
auto UnOp<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string UnOp<T>::getOp() { return this->op; }

template <typename T>
Expr<T> *UnOp<T>::getExpr() { return this->expr; }

template <typename T>
UnOp<T>::~UnOp()
{
    delete expr;
}

/************************************/
/*           BinOp class            */
/************************************/

template <typename T>
BinOp<T>::BinOp(const std::string op, Expr<T> *left_expr, Expr<T> *right_expr) : op(op), left_expr(left_expr), right_expr(right_expr) {}

template <typename T>
auto BinOp<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string BinOp<T>::getOp() { return this->op; }

template <typename T>
Expr<T> *BinOp<T>::getLeft_expr() { return this->left_expr; }

template <typename T>
Expr<T> *BinOp<T>::getRight_expr() { return this->right_expr; }

template <typename T>
BinOp<T>::~BinOp()
{
    delete left_expr;
    delete right_expr;
}

/************************************/
/*           Call class             */
/************************************/

template <typename T>
Call<T>::Call(const std::string method_name, std::vector<Expr<T> *> *expr_list, Expr<T> *obj_expr)
    : obj_expr(obj_expr), method_name(method_name), expr_list(expr_list) {}

template <typename T>
auto Call<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Call<T>::getMethod_name() { return this->method_name; }

template <typename T>
Expr<T> *Call<T>::getObj_expr() { return this->obj_expr; }

template <typename T>
std::vector<Expr<T> *> *Call<T>::getExpr_list() { return this->expr_list; }

template <typename T>
void Call<T>::AddExpr(Expr<T> *e) { expr_list->push_back(e); }

template <typename T>
Call<T>::~Call()
{
    for (auto e : *expr_list)
        delete e;
    delete obj_expr;
}

/************************************/
/*            New class             */
/************************************/

template <typename T>
New<T>::New(const std::string type_name) : type_name(type_name) {}

template <typename T>
auto New<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string New<T>::getType_name() { return this->type_name; }

template <typename T>
New<T>::~New() {}

/************************************/
/*      ObjectIdentifier class      */
/************************************/

template <typename T>
ObjectIdentifier<T>::ObjectIdentifier(const std::string name) : name(name) {}

template <typename T>
auto ObjectIdentifier<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string ObjectIdentifier<T>::getName() { return this->name; }

template <typename T>
ObjectIdentifier<T>::~ObjectIdentifier() {}

/************************************/
/*           Self class             */
/************************************/

template <typename T>
Self<T>::Self(const std::string self) : self(self) {}

template <typename T>
auto Self<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Self<T>::getSelf() { return this->self; }

template <typename T>
Self<T>::~Self() {}

/************************************/
/*            Par class             */
/************************************/

template <typename T>
Par<T>::Par() {}

template <typename T>
auto Par<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
Par<T>::~Par() {}

/************************************/
/*      IntegerLiteral class        */
/************************************/

template <typename T>
IntegerLiteral<T>::IntegerLiteral(int value) : value(value) {}

template <typename T>
auto IntegerLiteral<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
int IntegerLiteral<T>::getValue() { return this->value; }

template <typename T>
IntegerLiteral<T>::~IntegerLiteral() {}

/************************************/
/*       StringLiteral class        */
/************************************/

template <typename T>
StringLiteral<T>::StringLiteral(const std::string stringVal) : stringVal(stringVal) {}

template <typename T>
auto StringLiteral<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string StringLiteral<T>::getStringVal() { return stringVal; }

template <typename T>
StringLiteral<T>::~StringLiteral() {}

/************************************/
/*       BooleanLiteral class       */
/************************************/

template <typename T>
BooleanLiteral<T>::BooleanLiteral(const std::string val) : val(val) {}

template <typename T>
auto BooleanLiteral<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string BooleanLiteral<T>::getVal() { return val; }

template <typename T>
BooleanLiteral<T>::~BooleanLiteral() {}

/************************************/
/*           Field class            */
/************************************/

template <typename T>
Field<T>::Field(const std::string name, Type<T> type, Expr<T> *init_expr)
    : name(name), type(type), init_expr(init_expr) {}

template <typename T>
auto Field<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Field<T>::getName() { return name; }

template <typename T>
Type<T> Field<T>::getType() { return type; }

template <typename T>
Expr<T> *Field<T>::getInit_expr() { return init_expr; }

template <typename T>
Field<T>::~Field()
{
    delete init_expr;
}

/************************************/
/*           Method class           */
/************************************/

template <typename T>
Method<T>::Method(const std::string name, std::vector<Formal<T> *> *formals, Type<T> ret_type, Block<T> *block)
    : name(name), formals(formals), ret_type(ret_type), block(block) {}

template <typename T>
auto Method<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Method<T>::getName() { return name; }

template <typename T>
std::vector<Formal<T> *> *Method<T>::getFormals() { return formals; }

template <typename T>
Type<T> Method<T>::getRet_type() { return ret_type; }

template <typename T>
Block<T> *Method<T>::getBlock() { return block; }

template <typename T>
void Method<T>::AddFormal(Formal<T> *f) { formals->push_back(f); }

template <typename T>
Method<T>::~Method()
{
    for (auto f : *formals)
        delete f;
    delete block;
}

/************************************/
/*           Class class            */
/************************************/

template <typename T>
Class<T>::Class(const std::string name, std::vector<Method<T> *> *methods, std::vector<Field<T> *> *fields, const std::string parent)
    : name(name), parent(parent), methods(methods), fields(fields) {}

template <typename T>
auto Class<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const std::string Class<T>::getName() { return name; }

template <typename T>
const std::string Class<T>::getParent() { return parent; }

template <typename T>
std::vector<Method<T> *> *Class<T>::getMethods() { return methods; }

template <typename T>
std::vector<Field<T> *> *Class<T>::getFields() { return fields; }

template <typename T>
void Class<T>::AddMethod(Method<T> *m) { methods->push_back(m); }

template <typename T>
void Class<T>::AddField(Field<T> *f) { fields->push_back(f); }

template <typename T>
Class<T>::~Class()
{
    for (auto m : *methods)
        delete m;
    for (auto f : *fields)
        delete f;
}

/************************************/
/*          Program class           */
/************************************/

template <typename T>
Program<T>::Program(std::vector<Class<T> *> *classes) : classes(classes) {}

template <typename T>
auto Program<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
std::vector<Class<T> *> *Program<T>::getClasses() { return classes; }

template <typename T>
void Program<T>::AddClass(Class<T> *c) { classes->push_back(c); }

template <typename T>
Program<T>::~Program()
{
    for (auto c : *classes)
        delete c;
}

/************************************/
/*        EvalVisitor class         */
/************************************/

PrintVisitor::PrintVisitor()
{
}

void PrintVisitor::visit(Type<void> &type)
{
    std::cout << type.getType();
}

void PrintVisitor::visit(Formal<void> &formal)
{
    std::cout << formal.getName() << " : ";
    formal.getType().accept(*this);
}

void PrintVisitor::visit(Block<void> &block)
{
    std::cout << "[";
    if (!block.getExpr_list()->empty())
    {
        for (unsigned long i = 0; i < block.getExpr_list()->size(); i++)
        {
            (*block.getExpr_list())[i]->accept(*this);
            if (i == block.getExpr_list()->size() - 1)
                break;
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void PrintVisitor::visit(Conditional<void> &conditional)
{
    std::cout << "If(";

    conditional.getCond_expr()->accept(*this);
    std::cout << ", ";

    conditional.getThen_expr()->accept(*this);

    if (conditional.getElse_expr() != nullptr)
    {
        std::cout << ", ";
        conditional.getElse_expr()->accept(*this);
    }
    std::cout << ")";
}

void PrintVisitor::visit(While<void> &while_)
{
    std::cout << "While(";

    while_.getCond_expr()->accept(*this);
    std::cout << ", ";

    while_.getBody_expr()->accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(Let<void> &let)
{
    std::cout << "Let(" << let.getName() << ", ";

    let.getType().accept(*this);
    std::cout << ", ";

    if (let.getInit_expr() != nullptr)
    {
        let.getInit_expr()->accept(*this);
        std::cout << ", ";
    }

    let.getScope_expr()->accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(Assign<void> &assign)
{
    std::cout << "Assign(" << assign.getName() << ", ";
    assign.getExpr()->accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(UnOp<void> &unOp)
{
    std::cout << "UnOp(" << unOp.getOp() << ", ";
    unOp.getExpr()->accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(BinOp<void> &binOp)
{
    std::cout << "BinOp(" << binOp.getOp() << ", ";
    binOp.getLeft_expr()->accept(*this);
    std::cout << ", ";
    binOp.getRight_expr()->accept(*this);
    std::cout << ")";
}

void PrintVisitor::visit(Call<void> &call)
{
    std::cout << "Call(";

    if (call.getObj_expr() != nullptr)
        call.getObj_expr()->accept(*this);

    else
        std::cout << "self";

    std::cout << ", " << call.getMethod_name() << ", ";

    std::cout << "[";
    if (!call.getExpr_list()->empty())
    {
        for (unsigned long i = 0; i < call.getExpr_list()->size(); i++)
        {
            (*call.getExpr_list())[i]->accept(*this);
            if (i == call.getExpr_list()->size() - 1)
                break;
            else
                std::cout << ", ";
        }
    }
    std::cout << "]";
    std::cout << ")";
}

void PrintVisitor::visit(New<void> &new_)
{
    std::cout << "New(" << new_.getType_name() << ")";
}

void PrintVisitor::visit(ObjectIdentifier<void> &objectIdentifier)
{
    std::cout << objectIdentifier.getName();
}
void PrintVisitor::visit(Self<void> &self)
{
    std::cout << self.getSelf();
}

void PrintVisitor::visit(Par<void> &par)
{
    (void)par;
    std::cout << "()";
}

void PrintVisitor::visit(IntegerLiteral<void> &intergerLitteral)
{
    std::cout << intergerLitteral.getValue();
}

void PrintVisitor::visit(StringLiteral<void> &stringLitteral)
{
    std::cout << "\"" << stringLitteral.getStringVal() << "\"";
}

void PrintVisitor::visit(BooleanLiteral<void> &booleanLitteral)
{
    std::cout << booleanLitteral.getVal();
}

void PrintVisitor::visit(Field<void> &field)
{
    std::cout << "Field(" << field.getName() << ", ";

    field.getType().accept(*this);

    if (field.getInit_expr() != nullptr)
    {
        std::cout << ", ";
        field.getInit_expr()->accept(*this);
    }

    std::cout << ")";
}

void PrintVisitor::visit(Method<void> &method)
{
    std::cout << "Method(" << method.getName() << ", ";

    std::cout << "[";
    if (!method.getFormals()->empty())
    {
        for (unsigned long i = 0; i < method.getFormals()->size(); i++)
        {
            (*method.getFormals())[i]->accept(*this);
            if (i == method.getFormals()->size() - 1)
                std::cout << "], ";
            else
                std::cout << ", ";
        }
    }
    else
        std::cout << "], ";

    method.getRet_type().accept(*this);
    std::cout << ", ";

    method.getBlock()->accept(*this);

    std::cout << ")";
}

void PrintVisitor::visit(Class<void> &class_)
{
    std::cout << "Class(" << class_.getName() << ", ";

    if (class_.getParent() != "")
        std::cout << class_.getParent();
    else
        std::cout << "Object";

    std::cout << ", [";
    if (!class_.getFields()->empty())
    {
        for (unsigned long i = 0; i < class_.getFields()->size(); i++)
        {
            (*class_.getFields())[i]->accept(*this);
            if (i == class_.getFields()->size() - 1)
                break;
            else
                std::cout << ", ";
        }
    }
    std::cout << "],";

    if (!class_.getMethods()->empty())
    {
        std::cout << std::endl;
        std::cout << "[";
        for (unsigned long i = 0; i < class_.getMethods()->size(); i++)
        {
            (*class_.getMethods())[i]->accept(*this);
            if (i == class_.getMethods()->size() - 1)
                std::cout << "]";
            else
                std::cout << "," << std::endl;
        }
    }
    else
        std::cout << "[]";
    std::cout << ")";
}

void PrintVisitor::visit(Program<void> &program)
{
    std::cout << "[";
    if (!program.getClasses()->empty())
    {
        for (unsigned long i = 0; i < program.getClasses()->size(); i++)
        {
            (*program.getClasses())[i]->accept(*this);
            if (i == program.getClasses()->size() - 1)
                std::cout << "]";
            else
                std::cout << "," << std::endl;
        }
    }
    else
        std::cout << "[]" << std::endl;

    std::cout << std::endl;
}

PrintVisitor::~PrintVisitor()
{
}

template class Type<void>;
template class Formal<void>;
template class Block<void>;
template class Conditional<void>;
template class While<void>;
template class Let<void>;
template class Assign<void>;
template class UnOp<void>;
template class BinOp<void>;
template class Call<void>;
template class New<void>;
template class ObjectIdentifier<void>;
template class Self<void>;
template class Par<void>;
template class IntegerLiteral<void>;
template class StringLiteral<void>;
template class BooleanLiteral<void>;
template class Field<void>;
template class Method<void>;
template class Class<void>;
template class Program<void>;