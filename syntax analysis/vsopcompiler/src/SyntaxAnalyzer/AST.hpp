#ifndef _AST_HPP
#define _AST_HPP

#include <string>
#include <vector>

/************************************************/
/*     Forward declaration Vistor interface     */
/************************************************/
template<typename T>
class Visitor;

/************************************/
/*            Expr class            */
/************************************/

template <typename T>
class Expr
{
public:
    virtual auto accept(Visitor<T> &v) -> T = 0;
    virtual ~Expr() = 0;
};

/************************************/
/*            Type class            */
/************************************/

template <typename T>
class Type : public Expr<T>
{
public:
    Type(const std::string type);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_type();
    ~Type();

private:
    const std::string type;
};

/************************************/
/*           Formal class           */
/************************************/

// method can have zero or more formal parameters (arguments)

template <typename T>
class Formal : public Expr<T>
{
public:
    Formal(const std::string name, Type<T> type);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    Type<T> get_type();
    ~Formal();

private:
    const std::string name;
    Type<T> type;
};

/************************************/
/*           Block class            */
/************************************/

template <typename T>
class Block : public Expr<T>
{
public:
    Block(std::vector<Expr<T> *> *blockExrps);
    auto accept(Visitor<T> &v) -> T override;
    std::vector<Expr<T> *> *get_blockExrps();
    void Add_expr(Expr<T> *expr);
    ~Block();

private:
    std::vector<Expr<T> *> *blockExrps;
};

/************************************/
/*        Conditional class         */
/************************************/

template <typename T>
class Conditional : public Expr<T>
{
public:
    Conditional(Expr<T> *cond_expr, Expr<T> *then_expr, Expr<T> *else_expr = nullptr);
    auto accept(Visitor<T> &v) -> T override;
    Expr<T> *getCond_expr();
    Expr<T> *getThen_expr();
    Expr<T> *getElse_expr();
    ~Conditional();

private:
    Expr<T> *cond_expr;
    Expr<T> *then_expr;
    Expr<T> *else_expr;
};

/************************************/
/*         WhileLoop class          */
/************************************/

template <typename T>
class WhileLoop : public Expr<T>
{
public:
    WhileLoop(Expr<T> *cond_expr, Expr<T> *body_expr);
    auto accept(Visitor<T> &v) -> T override;
    Expr<T> *getCond_expr();
    Expr<T> *getBody_expr();
    ~WhileLoop();

private:
    Expr<T> *cond_expr;
    Expr<T> *body_expr;
};

/************************************/
/*            Let class             */
/************************************/

template <typename T>
class Let : public Expr<T>
{
public:
    Let(const std::string name, Type<T> type, Expr<T> *scope_expr, Expr<T> *init_expr = nullptr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    Type<T> get_type();
    Expr<T> *getInit_expr();
    Expr<T> *getScope_expr();
    ~Let();

private:
    const std::string name;
    Type<T> type;
    Expr<T> *init_expr;
    Expr<T> *scope_expr;
};

/************************************/
/*           Assign class           */
/************************************/

template <typename T>
class Assign : public Expr<T>
{
public:
    Assign(const std::string name, Expr<T> *expr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    Expr<T> *getExpr();
    ~Assign();

private:
    const std::string name;
    Expr<T> *expr;
};

/************************************/
/*           UnOp class             */
/************************************/

template <typename T>
class UnOp : public Expr<T>
{
public:
    UnOp(const std::string op, Expr<T> *expr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string getOp();
    Expr<T> *getExpr();
    ~UnOp();

private:
    const std::string op;
    Expr<T> *expr;
};

/************************************/
/*           BinOp class            */
/************************************/

template <typename T>
class BinOp : public Expr<T>
{
public:
    BinOp(const std::string op, Expr<T> *left_expr, Expr<T> *right_expr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string getOp();
    Expr<T> *getLeft_expr();
    Expr<T> *getRight_expr();
    ~BinOp();

private:
    const std::string op;
    Expr<T> *left_expr;
    Expr<T> *right_expr;
};

/************************************/
/*           Call class             */
/************************************/

template <typename T>
class Call : public Expr<T>
{
public:
    Call(const std::string method_name, std::vector<Expr<T> *> *expr_list, Expr<T> *obj_expr = nullptr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string getMethod_name();
    Expr<T> *getObj_expr();
    std::vector<Expr<T> *> *getExpr_list();
    void Add_expr(Expr<T> *expr);
    ~Call();

private:
    Expr<T> *obj_expr;
    const std::string method_name;
    std::vector<Expr<T> *> *expr_list;
};

/************************************/
/*            New class             */
/************************************/

template <typename T>
class New : public Expr<T>
{
public:
    New(const std::string type_name);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_type_name();
    ~New();

private:
    const std::string type_name;
};

/************************************/
/*      ObjectIdentifier class      */
/************************************/

template <typename T>
class ObjectIdentifier : public Expr<T>
{
public:
    ObjectIdentifier(const std::string name);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    ~ObjectIdentifier();

private:
    const std::string name;
};

/************************************/
/*           Self class             */
/************************************/

template <typename T>
class Self : public Expr<T>
{
public:
    Self(const std::string self = "self");
    auto accept(Visitor<T> &v) -> T override;
    const std::string getSelf();
    ~Self();

private:
    const std::string self;
};

/************************************/
/*            Par class             */
/************************************/

template <typename T>
class Par : public Expr<T>
{
public:
    Par();
    auto accept(Visitor<T> &v) -> T override;
    ~Par();
};

/************************************/
/*      IntegerLiteral class        */
/************************************/

template <typename T>
class IntegerLiteral : public Expr<T>
{
public:
    IntegerLiteral(int value);
    auto accept(Visitor<T> &v) -> T override;
    int getValue();
    ~IntegerLiteral();

private:
    int value;
};

/************************************/
/*       StringLiteral class        */
/************************************/

template <typename T>
class StringLiteral : public Expr<T>
{
public:
    StringLiteral(const std::string str);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_str();
    ~StringLiteral();

private:
    const std::string str;
};

/************************************/
/*       BooleanLiteral class       */
/************************************/

template <typename T>
class BooleanLiteral : public Expr<T>
{
public:
    BooleanLiteral(const std::string boolean);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_bool();
    ~BooleanLiteral();

private:
    const std::string boolean;
};

/************************************/
/*           Field class            */
/************************************/

template <typename T>
class Field : public Expr<T>
{
public:
    Field(const std::string name, Type<T> type, Expr<T> *init_expr);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    Type<T> get_type();
    Expr<T> *getInit_expr();
    ~Field();

private:
    const std::string name;
    Type<T> type;
    Expr<T> *init_expr;
};

/************************************/
/*           Method class           */
/************************************/

template <typename T>
class Method : public Expr<T>
{
public:
    Method(const std::string name, std::vector<Formal<T> *> *formals, Type<T> ret_type, Block<T> *block);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    std::vector<Formal<T> *> *get_formals();
    Type<T> getRet_type();
    Block<T> *get_block();
    void add_formal(Formal<T> *formal);
    ~Method();

private:
    const std::string name;
    std::vector<Formal<T> *> *formals;
    Type<T> ret_type;
    Block<T> *block;
};

/************************************/
/*           Class class            */
/************************************/

template <typename T>
class Class : public Expr<T>
{
public:
    Class(const std::string name, const std::string parent, std::vector<Field<T> *> *fields, std::vector<Method<T> *> *methods);
    auto accept(Visitor<T> &v) -> T override;
    const std::string get_name();
    const std::string getParent();
    std::vector<Field<T> *> *getFields();
    std::vector<Method<T> *> *getMethods();
    void AddMethod(Method<T> *method);
    void AddField(Field<T> *field);
    ~Class();

private:
    const std::string name;
    const std::string parent;
    std::vector<Field<T> *> *fields;
    std::vector<Method<T> *> *methods;
};

/************************************/
/*          Program class           */
/************************************/

template <typename T>
class Program : public Expr<T>
{
public:
    //Program();
    Program(std::vector<Class<T> *> *classes);
    auto accept(Visitor<T> &v) -> T override;
    std::vector<Class<T> *> *getClasses();
    void AddClass(Class<T> *c);
    ~Program();

private:
    std::vector<Class<T> *> *classes;
};

/************************************/
/*         Vistor interface         */
/************************************/

template <typename T>
class Visitor
{
public:
    virtual T visit(class Type<T> &type) = 0;
    virtual T visit(class Formal<T> &formal) = 0;
    virtual T visit(class Block<T> &block) = 0;
    virtual T visit(class Conditional<T> &conditional) = 0;
    virtual T visit(class WhileLoop<T> &whileLoop) = 0;
    virtual T visit(class Let<T> &let) = 0;
    virtual T visit(class Assign<T> &assign) = 0;
    virtual T visit(class UnOp<T> &unOp) = 0;
    virtual T visit(class BinOp<T> &binOp) = 0;
    virtual T visit(class Call<T> &call) = 0;
    virtual T visit(class New<T> &new_) = 0;
    virtual T visit(class ObjectIdentifier<T> &objectIdentifier) = 0;
    virtual T visit(class Self<T> &self) = 0;
    virtual T visit(class Par<T> &par) = 0;
    virtual T visit(class IntegerLiteral<T> &intergerLitteral) = 0;
    virtual T visit(class StringLiteral<T> &stringLitteral) = 0;
    virtual T visit(class BooleanLiteral<T> &booleanLitteral) = 0;
    virtual T visit(class Field<T> &field) = 0;
    virtual T visit(class Method<T> &method) = 0;
    virtual T visit(class Class<T> &class_) = 0;
    virtual T visit(class Program<T> &program) = 0;
};

/************************************/
/*        EvalVisitor class         */
/************************************/

class PrintVisitor : public Visitor<void>
{
public:
    PrintVisitor();
    void visit(Type<void> &type);
    void visit(Formal<void> &formal);
    void visit(Block<void> &block);
    void visit(Conditional<void> &conditional);
    void visit(WhileLoop<void> &whileLoop);
    void visit(Let<void> &let);
    void visit(Assign<void> &assign);
    void visit(UnOp<void> &unOp);
    void visit(BinOp<void> &binOp);
    void visit(Call<void> &call);
    void visit(New<void> &new_);
    void visit(ObjectIdentifier<void> &objectIdentifier);
    void visit(Self<void> &self);
    void visit(Par<void> &par);
    void visit(IntegerLiteral<void> &intergerLitteral);
    void visit(StringLiteral<void> &stringLitteral);
    void visit(BooleanLiteral<void> &booleanLitteral);
    void visit(Field<void> &field);
    void visit(Method<void> &method);
    void visit(Class<void> &class_);
    void visit(Program<void> &program);
    ~PrintVisitor();
};

#endif