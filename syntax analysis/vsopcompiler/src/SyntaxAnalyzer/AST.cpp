#include "AST.hpp"
#include <iostream>
#include <memory>

using std::make_unique;
using std::unique_ptr;
using std::string;
using std::cout;
using std::endl;

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
Type<T>::Type(const string type) : type(type) {}

template <typename T>
auto Type<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Type<T>::get_type() { return this->type; }

template <typename T>
Type<T>::~Type() {}

/************************************/
/*           Formal class           */
/************************************/

template <typename T>
Formal<T>::Formal(const string name, Type<T> type) : name(name), type(type) {}

template <typename T>
auto Formal<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Formal<T>::get_name() { return this->name; }

template <typename T>
Type<T> Formal<T>::get_type() { return this->type; }

template <typename T>
Formal<T>::~Formal() {}

/************************************/
/*           Block class            */
/************************************/

template <typename T>
Block<T>::Block(std::vector<Expr<T> *> *blockExrps) : blockExrps(blockExrps) {}

template <typename T>
auto Block<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
std::vector<Expr<T> *> *Block<T>::get_blockExrps() { return this->blockExrps; }

template <typename T>
void Block<T>::Add_expr(Expr<T> *expr) { blockExrps->push_back(expr); }

template <typename T>
Block<T>::~Block()
{
    for (auto block : *blockExrps)
        delete block;
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
/*           WhileLoop class            */
/************************************/

template <typename T>
WhileLoop<T>::WhileLoop(Expr<T> *cond_expr, Expr<T> *body_expr)
    : cond_expr(cond_expr), body_expr(body_expr) {}

template <typename T>
auto WhileLoop<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
Expr<T> *WhileLoop<T>::getCond_expr() { return this->cond_expr; }

template <typename T>
Expr<T> *WhileLoop<T>::getBody_expr() { return this->body_expr; }

template <typename T>
WhileLoop<T>::~WhileLoop()
{
    delete cond_expr;
    delete body_expr;
}

/************************************/
/*            Let class             */
/************************************/

template <typename T>
Let<T>::Let(const string name, Type<T> type, Expr<T> *scope_expr, Expr<T> *init_expr)
    : name(name), type(type), init_expr(init_expr), scope_expr(scope_expr) {}

template <typename T>
auto Let<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Let<T>::get_name() { return this->name; }

template <typename T>
Type<T> Let<T>::get_type() { return this->type; }

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
Assign<T>::Assign(const string name, Expr<T> *expr) : name(name), expr(expr) {}

template <typename T>
auto Assign<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Assign<T>::get_name() { return this->name; }

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
UnOp<T>::UnOp(const string op, Expr<T> *expr) : op(op), expr(expr) {}

template <typename T>
auto UnOp<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string UnOp<T>::getOp() { return this->op; }

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
BinOp<T>::BinOp(const string op, Expr<T> *left_expr, Expr<T> *right_expr) : op(op), left_expr(left_expr), right_expr(right_expr) {}

template <typename T>
auto BinOp<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string BinOp<T>::getOp() { return this->op; }

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
Call<T>::Call(const string method_name, std::vector<Expr<T> *> *expr_list, Expr<T> *obj_expr)
    : obj_expr(obj_expr), method_name(method_name), expr_list(expr_list) {}

template <typename T>
auto Call<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Call<T>::getMethod_name() { return this->method_name; }

template <typename T>
Expr<T> *Call<T>::getObj_expr() { return this->obj_expr; }

template <typename T>
std::vector<Expr<T> *> *Call<T>::getExpr_list() { return this->expr_list; }

template <typename T>
void Call<T>::Add_expr(Expr<T> *expr) { expr_list->push_back(expr); }

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
New<T>::New(const string type_name) : type_name(type_name) {}

template <typename T>
auto New<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string New<T>::get_type_name() { return this->type_name; }

template <typename T>
New<T>::~New() {}

/************************************/
/*      ObjectIdentifier class      */
/************************************/

template <typename T>
ObjectIdentifier<T>::ObjectIdentifier(const string name) : name(name) {}

template <typename T>
auto ObjectIdentifier<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string ObjectIdentifier<T>::get_name() { return this->name; }

template <typename T>
ObjectIdentifier<T>::~ObjectIdentifier() {}

/************************************/
/*           Self class             */
/************************************/

template <typename T>
Self<T>::Self(const string self) : self(self) {}

template <typename T>
auto Self<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Self<T>::getSelf() { return this->self; }

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
StringLiteral<T>::StringLiteral(const string str) : str(str) {}

template <typename T>
auto StringLiteral<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string StringLiteral<T>::get_str() { return str; }

template <typename T>
StringLiteral<T>::~StringLiteral() {}

/************************************/
/*       BooleanLiteral class       */
/************************************/

template <typename T>
BooleanLiteral<T>::BooleanLiteral(const string boolean) : boolean(boolean) {}

template <typename T>
auto BooleanLiteral<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string BooleanLiteral<T>::get_bool() { return this->boolean; }

template <typename T>
BooleanLiteral<T>::~BooleanLiteral() {}

/************************************/
/*           Field class            */
/************************************/

template <typename T>
Field<T>::Field(const string name, Type<T> type, Expr<T> *init_expr)
    : name(name), type(type), init_expr(init_expr) {}

template <typename T>
auto Field<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Field<T>::get_name() { return name; }

template <typename T>
Type<T> Field<T>::get_type() { return type; }

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
Method<T>::Method(const string name, std::vector<Formal<T> *> *formals, Type<T> ret_type, Block<T> *block)
    : name(name), formals(formals), ret_type(ret_type), block(block) {}

template <typename T>
auto Method<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Method<T>::get_name() { return name; }

template <typename T>
std::vector<Formal<T> *> *Method<T>::get_formals() { return this->formals; }

template <typename T>
Type<T> Method<T>::getRet_type() { return this->ret_type; }

template <typename T>
Block<T> *Method<T>::get_block() { return this->block; }

template <typename T>
void Method<T>::add_formal(Formal<T> *formal) { formals->push_back(formal); }

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
Class<T>::Class(const string name, const string parent, std::vector<Field<T> *> *fields, std::vector<Method<T> *> *methods)
    : name(name), parent(parent), fields(fields), methods(methods) {}

template <typename T>
auto Class<T>::accept(Visitor<T> &v) -> T { return v.visit(*this); }

template <typename T>
const string Class<T>::get_name() { return name; }

template <typename T>
const string Class<T>::getParent() { return parent; }

template <typename T>
std::vector<Field<T> *> *Class<T>::getFields() { return fields; }

template <typename T>
std::vector<Method<T> *> *Class<T>::getMethods() { return methods; }

template <typename T>
void Class<T>::AddField(Field<T> *field) { fields->push_back(field); }

template <typename T>
void Class<T>::AddMethod(Method<T> *method) { methods->push_back(method); }

template <typename T>
Class<T>::~Class()
{
    for (auto method : *methods)
        delete method;
    for (auto field : *fields)
        delete field;
}

/************************************/
/*          Program class           */
/************************************/

//template <typename T>
//Program<T>::Program()
//{
//}

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
    cout << type.get_type();
}

void PrintVisitor::visit(Formal<void> &formal)
{
    cout << formal.get_name() << " : ";
    formal.get_type().accept(*this);
}

void PrintVisitor::visit(Block<void> &block)
{
    cout << "[";
    if (!block.get_blockExrps()->empty())
    {
        for (unsigned long i = 0; i < block.get_blockExrps()->size(); i++)
        {
            (*block.get_blockExrps())[i]->accept(*this);
            if (i == block.get_blockExrps()->size() - 1)
                break;
            cout << ", ";
        }
    }
    cout << "]";
}

void PrintVisitor::visit(Conditional<void> &conditional)
{
    cout << "If(";
    conditional.getCond_expr()->accept(*this);

    cout << ", ";

    conditional.getThen_expr()->accept(*this);

    if (conditional.getElse_expr() != nullptr)
    {
        cout << ", ";
        conditional.getElse_expr()->accept(*this);
    }
    cout << ")";
}

void PrintVisitor::visit(WhileLoop<void> &whileLoop)
{
    cout << "While(";

    whileLoop.getCond_expr()->accept(*this);
    cout << ", ";

    whileLoop.getBody_expr()->accept(*this);
    cout << ")";
}

void PrintVisitor::visit(Let<void> &let)
{
    cout << "Let(" << let.get_name() << ", ";

    let.get_type().accept(*this);
    cout << ", ";

    if (let.getInit_expr() != nullptr)
    {
        let.getInit_expr()->accept(*this);
        cout << ", ";
    }

    let.getScope_expr()->accept(*this);
    cout << ")";
}

void PrintVisitor::visit(Assign<void> &assign)
{
    cout << "Assign(" << assign.get_name() << ", ";
    assign.getExpr()->accept(*this);
    cout << ")";
}

void PrintVisitor::visit(UnOp<void> &unOp)
{
    cout << "UnOp(" << unOp.getOp() << ", ";
    unOp.getExpr()->accept(*this);
    cout << ")";
}

void PrintVisitor::visit(BinOp<void> &binOp)
{
    cout << "BinOp(" << binOp.getOp() << ", ";
    binOp.getLeft_expr()->accept(*this);
    cout << ", ";
    binOp.getRight_expr()->accept(*this);
    cout << ")";
}

void PrintVisitor::visit(Call<void> &call)
{
    cout << "Call(";

    if (call.getObj_expr() != nullptr)
        call.getObj_expr()->accept(*this);

    else
        cout << "self";

    cout << ", " << call.getMethod_name() << ", ";

    cout << "[";
    if (!call.getExpr_list()->empty())
    {
        for (unsigned long i = 0; i < call.getExpr_list()->size(); i++)
        {
            (*call.getExpr_list())[i]->accept(*this);
            if (i == call.getExpr_list()->size() - 1)
                break;
            else
                cout << ", ";
        }
    }
    cout << "]";
    cout << ")";
}

void PrintVisitor::visit(New<void> &new_)
{
    cout << "New(" << new_.get_type_name() << ")";
}

void PrintVisitor::visit(ObjectIdentifier<void> &objectIdentifier)
{
    cout << objectIdentifier.get_name();
}
void PrintVisitor::visit(Self<void> &self)
{
    cout << self.getSelf();
}

void PrintVisitor::visit(Par<void> &par)
{
    (void)par;
    cout << "()";
}

void PrintVisitor::visit(IntegerLiteral<void> &intergerLitteral)
{
    cout << intergerLitteral.getValue();
}

void PrintVisitor::visit(StringLiteral<void> &stringLitteral)
{
    cout << stringLitteral.get_str();
}

void PrintVisitor::visit(BooleanLiteral<void> &booleanLitteral)
{
    cout << booleanLitteral.get_bool();
}

void PrintVisitor::visit(Field<void> &field)
{
    cout << "Field(" << field.get_name() << ", ";

    field.get_type().accept(*this);

    if (field.getInit_expr() != nullptr)
    {
        cout << ", ";
        field.getInit_expr()->accept(*this);
    }

    cout << ")";
}

void PrintVisitor::visit(Method<void> &method)
{
    cout << "Method(" << method.get_name() << ", ";

    cout << "[";
    if (!method.get_formals()->empty())
    {
        for (unsigned long i = 0; i < method.get_formals()->size(); i++)
        {
            (*method.get_formals())[i]->accept(*this);
            if (i == method.get_formals()->size() - 1)
                cout << "], ";
            else
                cout << ", ";
        }
    }
    else
        cout << "], ";

    method.getRet_type().accept(*this);
    cout << ", ";

    method.get_block()->accept(*this);

    cout << ")";
}

void PrintVisitor::visit(Class<void> &class_)
{
    cout << "Class(" << class_.get_name() << ", ";

    if (class_.getParent() != "")
        cout << class_.getParent();
    else
        cout << "Object";

    cout << ", [";
    if (!class_.getFields()->empty())
    {
        for (unsigned long i = 0; i < class_.getFields()->size(); i++)
        {
            (*class_.getFields())[i]->accept(*this);
            if (i == class_.getFields()->size() - 1)
                break;
            else
                cout << ", ";
        }
    }
    cout << "],";

    if (!class_.getMethods()->empty())
    {
        cout << endl;
        cout << "\t [";
        for (unsigned long i = 0; i < class_.getMethods()->size(); i++)
        {
            (*class_.getMethods())[i]->accept(*this);
            if (i == class_.getMethods()->size() - 1)
                cout << "]";
            else
                cout << ", ";
        }
    }
    else
        cout << "[]";
    cout << ")";

}

void PrintVisitor::visit(Program<void> &program)
{
    cout << "[";
    if (!program.getClasses()->empty())
    {
        for (unsigned long i = 0; i < program.getClasses()->size(); i++)
        {
            (*program.getClasses())[i]->accept(*this);
            if (i == program.getClasses()->size() - 1)
                cout << "]";
            else
                cout << "," << endl;
        }
    }
    else
        cout << "[]" << endl;

    cout << endl;
}

PrintVisitor::~PrintVisitor()
{
}

template class Type<void>;
template class Formal<void>;
template class Block<void>;
template class Conditional<void>;
template class WhileLoop<void>;
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