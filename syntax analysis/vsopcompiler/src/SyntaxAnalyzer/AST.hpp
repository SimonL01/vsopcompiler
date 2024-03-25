#ifndef _AST_HPP
#define _AST_HPP

#include <string>
#include <vector>

/************************************************/
/*     Forward declaration Vistor interface     */
/************************************************/

/**
 * @brief Forward declaration of the Visitor interface.
 *
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Visitor;

/************************************/
/*            Expr class            */
/************************************/

/**
 * @brief Base class representing an abstract expression node in the AST.
 *
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Expr
{
public:
    /**
     * @brief Virtual method to accept a visitor.
     *
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    virtual auto accept(Visitor<T> &v) -> T = 0;

    /**
     * @brief Virtual destructor for Expr class.
     */
    virtual ~Expr() = 0;
};

/************************************/
/*            Type class            */
/************************************/

/**
 * @brief Class representing a type expression node in the AST.
 *
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Type : public Expr<T>
{
public:
    /**
     * @brief Constructor for Type class.
     *
     * @param type The type represented by this node.
     */
    Type(const std::string type);

    /**
     * @brief Method to accept a visitor.
     *
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the type represented by this node.
     *
     * @return const std::string The type represented by this node.
     */
    const std::string get_type();

    /**
     * @brief Destructor for Type class.
     */
    ~Type();

private:
    const std::string type; /**< The type represented by this node. */
};

/************************************/
/*           Formal class           */
/************************************/

// method can have zero or more formal parameters (arguments)

/**
 * @brief Class representing a formal parameter node in the AST.
 *
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Formal : public Expr<T>
{
public:
    /**
     * @brief Constructor for Formal class.
     *
     * @param name The name of the formal parameter.
     * @param type The type of the formal parameter.
     */
    Formal(const std::string name, Type<T> type);

    /**
     * @brief Method to accept a visitor.
     *
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the formal parameter.
     *
     * @return const std::string The name of the formal parameter.
     */
    const std::string get_name();

    /**
     * @brief Get the type of the formal parameter.
     *
     * @return Type<T> The type of the formal parameter.
     */
    Type<T> get_type();

    /**
     * @brief Destructor for Formal class.
     */
    ~Formal();

private:
    const std::string name; /**< The name of the formal parameter. */
    Type<T> type;           /**< The type of the formal parameter. */
};

/************************************/
/*           Block class            */
/************************************/

/**
 * @brief Class representing a block expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Block : public Expr<T>
{
public:
    /**
     * @brief Constructor for Block class.
     * 
     * @param blockExrps Pointer to a vector containing expressions in the block.
     */
    Block(std::vector<Expr<T> *> *blockExrps);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the block expressions.
     * 
     * @return std::vector<Expr<T> *>* Pointer to a vector containing expressions in the block.
     */
    std::vector<Expr<T> *> *get_blockExrps();

    /**
     * @brief Add an expression to the block.
     * 
     * @param expr Pointer to the expression to be added.
     */
    void Add_expr(Expr<T> *expr);

    /**
     * @brief Destructor for Block class.
     */
    ~Block();

private:
    std::vector<Expr<T> *> *blockExrps; /**< Pointer to a vector containing expressions in the block. */
};

/************************************/
/*        Conditional class         */
/************************************/

/**
 * @brief Class representing a conditional expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Conditional : public Expr<T>
{
public:
    /**
     * @brief Constructor for Conditional class.
     * 
     * @param cond_expr Pointer to the condition expression.
     * @param then_expr Pointer to the 'then' expression.
     * @param else_expr Pointer to the 'else' expression (optional).
     */
    Conditional(Expr<T> *cond_expr, Expr<T> *then_expr, Expr<T> *else_expr = nullptr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the condition expression.
     * 
     * @return Expr<T>* Pointer to the condition expression.
     */
    Expr<T> *getCond_expr();

    /**
     * @brief Get the 'then' expression.
     * 
     * @return Expr<T>* Pointer to the 'then' expression.
     */
    Expr<T> *getThen_expr();

    /**
     * @brief Get the 'else' expression.
     * 
     * @return Expr<T>* Pointer to the 'else' expression.
     */
    Expr<T> *getElse_expr();

    /**
     * @brief Destructor for Conditional class.
     */
    ~Conditional();

private:
    Expr<T> *cond_expr; /**< Pointer to the condition expression. */
    Expr<T> *then_expr; /**< Pointer to the 'then' expression. */
    Expr<T> *else_expr; /**< Pointer to the 'else' expression. */
};


/************************************/
/*         WhileLoop class          */
/************************************/

/**
 * @brief Class representing a while loop expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class WhileLoop : public Expr<T>
{
public:
    /**
     * @brief Constructor for WhileLoop class.
     * 
     * @param cond_expr Pointer to the condition expression.
     * @param body_expr Pointer to the body expression.
     */
    WhileLoop(Expr<T> *cond_expr, Expr<T> *body_expr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the condition expression.
     * 
     * @return Expr<T>* Pointer to the condition expression.
     */
    Expr<T> *getCond_expr();

    /**
     * @brief Get the body expression.
     * 
     * @return Expr<T>* Pointer to the body expression.
     */
    Expr<T> *getBody_expr();

    /**
     * @brief Destructor for WhileLoop class.
     */
    ~WhileLoop();

private:
    Expr<T> *cond_expr; /**< Pointer to the condition expression. */
    Expr<T> *body_expr; /**< Pointer to the body expression. */
};

/************************************/
/*            Let class             */
/************************************/

/**
 * @brief Class representing a let expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Let : public Expr<T>
{
public:
    /**
     * @brief Constructor for Let class.
     * 
     * @param name The name of the variable being declared.
     * @param type The type of the variable.
     * @param scope_expr The scope expression where the variable is defined.
     * @param init_expr Optional initialization expression for the variable.
     */
    Let(const std::string name, Type<T> type, Expr<T> *scope_expr, Expr<T> *init_expr = nullptr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the variable.
     * 
     * @return const std::string Name of the variable.
     */
    const std::string get_name();

    /**
     * @brief Get the type of the variable.
     * 
     * @return Type<T> Type of the variable.
     */
    Type<T> get_type();

    /**
     * @brief Get the initialization expression of the variable.
     * 
     * @return Expr<T>* Pointer to the initialization expression.
     */
    Expr<T> *getInit_expr();

    /**
     * @brief Get the scope expression where the variable is defined.
     * 
     * @return Expr<T>* Pointer to the scope expression.
     */
    Expr<T> *getScope_expr();

    /**
     * @brief Destructor for Let class.
     */
    ~Let();

private:
    const std::string name; /**< The name of the variable. */
    Type<T> type; /**< The type of the variable. */
    Expr<T> *init_expr; /**< Pointer to the initialization expression. */
    Expr<T> *scope_expr; /**< Pointer to the scope expression. */
};

/************************************/
/*           Assign class           */
/************************************/

/**
 * @brief Class representing an assignment expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Assign : public Expr<T>
{
public:
    /**
     * @brief Constructor for Assign class.
     * 
     * @param name The name of the variable being assigned.
     * @param expr The expression being assigned to the variable.
     */
    Assign(const std::string name, Expr<T> *expr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the variable being assigned.
     * 
     * @return const std::string Name of the variable.
     */
    const std::string get_name();

    /**
     * @brief Get the expression being assigned to the variable.
     * 
     * @return Expr<T>* Pointer to the assignment expression.
     */
    Expr<T> *getExpr();

    /**
     * @brief Destructor for Assign class.
     */
    ~Assign();

private:
    const std::string name; /**< The name of the variable being assigned. */
    Expr<T> *expr; /**< Pointer to the assignment expression. */
};

/************************************/
/*           UnOp class             */
/************************************/

/**
 * @brief Class representing a unary operation expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class UnOp : public Expr<T>
{
public:
    /**
     * @brief Constructor for UnOp class.
     * 
     * @param op The unary operation.
     * @param expr The operand expression.
     */
    UnOp(const std::string op, Expr<T> *expr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the unary operation.
     * 
     * @return const std::string Unary operation.
     */
    const std::string getOp();

    /**
     * @brief Get the operand expression.
     * 
     * @return Expr<T>* Pointer to the operand expression.
     */
    Expr<T> *getExpr();

    /**
     * @brief Destructor for UnOp class.
     */
    ~UnOp();

private:
    const std::string op; /**< The unary operation. */
    Expr<T> *expr; /**< Pointer to the operand expression. */
};

/************************************/
/*           BinOp class            */
/************************************/

/**
 * @brief Class representing a binary operation expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class BinOp : public Expr<T>
{
public:
    /**
     * @brief Constructor for BinOp class.
     * 
     * @param op The binary operation.
     * @param left_expr Pointer to the left operand expression.
     * @param right_expr Pointer to the right operand expression.
     */
    BinOp(const std::string op, Expr<T> *left_expr, Expr<T> *right_expr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the binary operation.
     * 
     * @return const std::string Binary operation.
     */
    const std::string getOp();

    /**
     * @brief Get the left operand expression.
     * 
     * @return Expr<T>* Pointer to the left operand expression.
     */
    Expr<T> *getLeft_expr();

    /**
     * @brief Get the right operand expression.
     * 
     * @return Expr<T>* Pointer to the right operand expression.
     */
    Expr<T> *getRight_expr();

    /**
     * @brief Destructor for BinOp class.
     */
    ~BinOp();

private:
    const std::string op; /**< The binary operation. */
    Expr<T> *left_expr; /**< Pointer to the left operand expression. */
    Expr<T> *right_expr; /**< Pointer to the right operand expression. */
};

/**
 * @brief Class representing a function call expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Call : public Expr<T>
{
public:
    /**
     * @brief Constructor for Call class.
     * 
     * @param method_name The name of the method being called.
     * @param expr_list Pointer to a vector containing expressions as arguments to the method.
     * @param obj_expr Pointer to the object on which the method is called (optional).
     */
    Call(const std::string method_name, std::vector<Expr<T> *> *expr_list, Expr<T> *obj_expr = nullptr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the method being called.
     * 
     * @return const std::string Name of the method.
     */
    const std::string getMethod_name();

    /**
     * @brief Get the object on which the method is called.
     * 
     * @return Expr<T>* Pointer to the object expression.
     */
    Expr<T> *getObj_expr();

    /**
     * @brief Get the list of expressions representing the method arguments.
     * 
     * @return std::vector<Expr<T> *> Pointer to the vector containing method arguments.
     */
    std::vector<Expr<T> *> *getExpr_list();

    /**
     * @brief Add an expression to the list of method arguments.
     * 
     * @param expr Pointer to the expression to be added.
     */
    void Add_expr(Expr<T> *expr);

    /**
     * @brief Destructor for Call class.
     */
    ~Call();

private:
    Expr<T> *obj_expr; /**< Pointer to the object on which the method is called. */
    const std::string method_name; /**< Name of the method being called. */
    std::vector<Expr<T> *> *expr_list; /**< Pointer to the vector containing method arguments. */
};

/************************************/
/*            New class             */
/************************************/

/**
 * @brief Class representing a 'new' expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class New : public Expr<T>
{
public:
    /**
     * @brief Constructor for New class.
     * 
     * @param type_name The name of the type to be instantiated.
     */
    New(const std::string type_name);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the type being instantiated.
     * 
     * @return const std::string Name of the type.
     */
    const std::string get_type_name();

    /**
     * @brief Destructor for New class.
     */
    ~New();

private:
    const std::string type_name; /**< Name of the type being instantiated. */
};

/************************************/
/*      ObjectIdentifier class      */
/************************************/

/**
 * @brief Class representing an object identifier expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class ObjectIdentifier : public Expr<T>
{
public:
    /**
     * @brief Constructor for ObjectIdentifier class.
     * 
     * @param name The name of the object identifier.
     */
    ObjectIdentifier(const std::string name);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the object identifier.
     * 
     * @return const std::string Name of the object identifier.
     */
    const std::string get_name();

    /**
     * @brief Destructor for ObjectIdentifier class.
     */
    ~ObjectIdentifier();

private:
    const std::string name; /**< Name of the object identifier. */
};

/************************************/
/*           Self class             */
/************************************/

/**
 * @brief Class representing the 'self' keyword expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Self : public Expr<T>
{
public:
    /**
     * @brief Constructor for Self class.
     * 
     * @param self The string representation of 'self' keyword (optional, defaults to "self").
     */
    Self(const std::string self = "self");

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the string representation of 'self' keyword.
     * 
     * @return const std::string String representation of 'self' keyword.
     */
    const std::string getSelf();

    /**
     * @brief Destructor for Self class.
     */
    ~Self();

private:
    const std::string self; /**< String representation of 'self' keyword. */
};

/************************************/
/*            Par class             */
/************************************/

/**
 * @brief Class representing parentheses in expressions in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Par : public Expr<T>
{
public:
    /**
     * @brief Constructor for Par class.
     */
    Par();

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Destructor for Par class.
     */
    ~Par();
};

/************************************/
/*      IntegerLiteral class        */
/************************************/

/**
 * @brief Class representing an integer literal expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class IntegerLiteral : public Expr<T>
{
public:
    /**
     * @brief Constructor for IntegerLiteral class.
     * 
     * @param value The integer value of the literal.
     */
    IntegerLiteral(int value);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the integer value of the literal.
     * 
     * @return int Integer value.
     */
    int getValue();

    /**
     * @brief Destructor for IntegerLiteral class.
     */
    ~IntegerLiteral();

private:
    int value; /**< The integer value of the literal. */
};

/************************************/
/*       StringLiteral class        */
/************************************/

/**
 * @brief Class representing a string literal expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class StringLiteral : public Expr<T>
{
public:
    /**
     * @brief Constructor for StringLiteral class.
     * 
     * @param str The string value of the literal.
     */
    StringLiteral(const std::string str);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the string value of the literal.
     * 
     * @return const std::string String value.
     */
    const std::string get_str();

    /**
     * @brief Destructor for StringLiteral class.
     */
    ~StringLiteral();

private:
    const std::string str; /**< The string value of the literal. */
};

/************************************/
/*       BooleanLiteral class       */
/************************************/

/**
 * @brief Class representing a boolean literal expression node in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class BooleanLiteral : public Expr<T>
{
public:
    /**
     * @brief Constructor for BooleanLiteral class.
     * 
     * @param boolean The boolean value of the literal.
     */
    BooleanLiteral(const std::string boolean);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the boolean value of the literal.
     * 
     * @return const std::string Boolean value.
     */
    const std::string get_bool();

    /**
     * @brief Destructor for BooleanLiteral class.
     */
    ~BooleanLiteral();

private:
    const std::string boolean; /**< The boolean value of the literal. */
};

/************************************/
/*           Field class            */
/************************************/

/**
 * @brief Class representing a field declaration in a class definition in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Field : public Expr<T>
{
public:
    /**
     * @brief Constructor for Field class.
     * 
     * @param name The name of the field.
     * @param type The type of the field.
     * @param init_expr The initialization expression for the field.
     */
    Field(const std::string name, Type<T> type, Expr<T> *init_expr);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the field.
     * 
     * @return const std::string Name of the field.
     */
    const std::string get_name();

    /**
     * @brief Get the type of the field.
     * 
     * @return Type<T> Type of the field.
     */
    Type<T> get_type();

    /**
     * @brief Get the initialization expression for the field.
     * 
     * @return Expr<T>* Pointer to the initialization expression.
     */
    Expr<T> *getInit_expr();

    /**
     * @brief Destructor for Field class.
     */
    ~Field();

private:
    const std::string name; /**< The name of the field. */
    Type<T> type; /**< The type of the field. */
    Expr<T> *init_expr; /**< Pointer to the initialization expression. */
};


/************************************/
/*           Method class           */
/************************************/

/**
 * @brief Class representing a method declaration in a class definition in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Method : public Expr<T>
{
public:
    /**
     * @brief Constructor for Method class.
     * 
     * @param name The name of the method.
     * @param formals The formal parameters of the method.
     * @param ret_type The return type of the method.
     * @param block The block representing the method's body.
     */
    Method(const std::string name, std::vector<Formal<T> *> *formals, Type<T> ret_type, Block<T> *block);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the method.
     * 
     * @return const std::string Name of the method.
     */
    const std::string get_name();

    /**
     * @brief Get the formal parameters of the method.
     * 
     * @return std::vector<Formal<T> *> Pointer to the vector of formal parameters.
     */
    std::vector<Formal<T> *> *get_formals();

    /**
     * @brief Get the return type of the method.
     * 
     * @return Type<T> Return type of the method.
     */
    Type<T> getRet_type();

    /**
     * @brief Get the block representing the method's body.
     * 
     * @return Block<T>* Pointer to the block representing the method's body.
     */
    Block<T> *get_block();

    /**
     * @brief Add a formal parameter to the method.
     * 
     * @param formal Pointer to the formal parameter to be added.
     */
    void add_formal(Formal<T> *formal);

    /**
     * @brief Destructor for Method class.
     */
    ~Method();

private:
    const std::string name; /**< The name of the method. */
    std::vector<Formal<T> *> *formals; /**< Vector of formal parameters of the method. */
    Type<T> ret_type; /**< The return type of the method. */
    Block<T> *block; /**< Pointer to the block representing the method's body. */
};

/************************************/
/*           Class class            */
/************************************/

/**
 * @brief Class representing a class definition in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Class : public Expr<T>
{
public:
    /**
     * @brief Constructor for Class class.
     * 
     * @param name The name of the class.
     * @param parent The name of the parent class.
     * @param fields Vector of fields in the class.
     * @param methods Vector of methods in the class.
     */
    Class(const std::string name, const std::string parent, std::vector<Field<T> *> *fields, std::vector<Method<T> *> *methods);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the name of the class.
     * 
     * @return const std::string Name of the class.
     */
    const std::string get_name();

    /**
     * @brief Get the name of the parent class.
     * 
     * @return const std::string Name of the parent class.
     */
    const std::string getParent();

    /**
     * @brief Get the vector of fields in the class.
     * 
     * @return std::vector<Field<T> *> Pointer to the vector of fields.
     */
    std::vector<Field<T> *> *getFields();

    /**
     * @brief Get the vector of methods in the class.
     * 
     * @return std::vector<Method<T> *> Pointer to the vector of methods.
     */
    std::vector<Method<T> *> *getMethods();

    /**
     * @brief Add a method to the class.
     * 
     * @param method Pointer to the method to be added.
     */
    void AddMethod(Method<T> *method);

    /**
     * @brief Add a field to the class.
     * 
     * @param field Pointer to the field to be added.
     */
    void AddField(Field<T> *field);

    /**
     * @brief Destructor for Class class.
     */
    ~Class();

private:
    const std::string name; /**< The name of the class. */
    const std::string parent; /**< The name of the parent class. */
    std::vector<Field<T> *> *fields; /**< Vector of fields in the class. */
    std::vector<Method<T> *> *methods; /**< Vector of methods in the class. */
};

/************************************/
/*          Program class           */
/************************************/

/**
 * @brief Class representing the entire program in the AST.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Program : public Expr<T>
{
public:
    // Program();
    /**
     * @brief Constructor for Program class.
     * 
     * @param classes Vector of classes in the program.
     */
    Program(std::vector<Class<T> *> *classes);

    /**
     * @brief Method to accept a visitor.
     * 
     * @param v Reference to the visitor object.
     * @return T Result of visiting the element.
     */
    auto accept(Visitor<T> &v) -> T override;

    /**
     * @brief Get the vector of classes in the program.
     * 
     * @return std::vector<Class<T> *> Pointer to the vector of classes.
     */
    std::vector<Class<T> *> *getClasses();

    /**
     * @brief Add a class to the program.
     * 
     * @param c Pointer to the class to be added.
     */
    void AddClass(Class<T> *c);

    /**
     * @brief Destructor for Program class.
     */
    ~Program();

private:
    std::vector<Class<T> *> *classes; /**< Vector of classes in the program. */
};

/************************************/
/*         Visitor interface        */
/************************************/

/**
 * @brief Interface for visitor pattern to visit different types of AST nodes.
 * 
 * @tparam T Template parameter representing the return type of visitor methods.
 */
template <typename T>
class Visitor
{
public:
    /**
     * @brief Virtual method to visit a Type node.
     * 
     * @param type Reference to the Type node.
     * @return T Result of visiting the Type node.
     */
    virtual T visit(class Type<T> &type) = 0;

    /**
     * @brief Virtual method to visit a Formal node.
     * 
     * @param formal Reference to the Formal node.
     * @return T Result of visiting the Formal node.
     */
    virtual T visit(class Formal<T> &formal) = 0;

    /**
     * @brief Virtual method to visit a Block node.
     * 
     * @param block Reference to the Block node.
     * @return T Result of visiting the Block node.
     */
    virtual T visit(class Block<T> &block) = 0;

    /**
     * @brief Virtual method to visit a Conditional node.
     * 
     * @param conditional Reference to the Conditional node.
     * @return T Result of visiting the Conditional node.
     */
    virtual T visit(class Conditional<T> &conditional) = 0;

    /**
     * @brief Virtual method to visit a WhileLoop node.
     * 
     * @param whileLoop Reference to the WhileLoop node.
     * @return T Result of visiting the WhileLoop node.
     */
    virtual T visit(class WhileLoop<T> &whileLoop) = 0;

    /**
     * @brief Virtual method to visit a Let node.
     * 
     * @param let Reference to the Let node.
     * @return T Result of visiting the Let node.
     */
    virtual T visit(class Let<T> &let) = 0;

    /**
     * @brief Virtual method to visit an Assign node.
     * 
     * @param assign Reference to the Assign node.
     * @return T Result of visiting the Assign node.
     */
    virtual T visit(class Assign<T> &assign) = 0;

    /**
     * @brief Virtual method to visit a UnOp node.
     * 
     * @param unOp Reference to the UnOp node.
     * @return T Result of visiting the UnOp node.
     */
    virtual T visit(class UnOp<T> &unOp) = 0;

    /**
     * @brief Virtual method to visit a BinOp node.
     * 
     * @param binOp Reference to the BinOp node.
     * @return T Result of visiting the BinOp node.
     */
    virtual T visit(class BinOp<T> &binOp) = 0;

    /**
     * @brief Virtual method to visit a Call node.
     * 
     * @param call Reference to the Call node.
     * @return T Result of visiting the Call node.
     */
    virtual T visit(class Call<T> &call) = 0;

    /**
     * @brief Virtual method to visit a New node.
     * 
     * @param new_ Reference to the New node.
     * @return T Result of visiting the New node.
     */
    virtual T visit(class New<T> &new_) = 0;

    /**
     * @brief Virtual method to visit an ObjectIdentifier node.
     * 
     * @param objectIdentifier Reference to the ObjectIdentifier node.
     * @return T Result of visiting the ObjectIdentifier node.
     */
    virtual T visit(class ObjectIdentifier<T> &objectIdentifier) = 0;

    /**
     * @brief Virtual method to visit a Self node.
     * 
     * @param self Reference to the Self node.
     * @return T Result of visiting the Self node.
     */
    virtual T visit(class Self<T> &self) = 0;

    /**
     * @brief Virtual method to visit a Par node.
     * 
     * @param par Reference to the Par node.
     * @return T Result of visiting the Par node.
     */
    virtual T visit(class Par<T> &par) = 0;

    /**
     * @brief Virtual method to visit an IntegerLiteral node.
     * 
     * @param intergerLitteral Reference to the IntegerLiteral node.
     * @return T Result of visiting the IntegerLiteral node.
     */
    virtual T visit(class IntegerLiteral<T> &intergerLitteral) = 0;

    /**
     * @brief Virtual method to visit a StringLiteral node.
     * 
     * @param stringLitteral Reference to the StringLiteral node.
     * @return T Result of visiting the StringLiteral node.
     */
    virtual T visit(class StringLiteral<T> &stringLitteral) = 0;

    /**
     * @brief Virtual method to visit a BooleanLiteral node.
     * 
     * @param booleanLitteral Reference to the BooleanLiteral node.
     * @return T Result of visiting the BooleanLiteral node.
     */
    virtual T visit(class BooleanLiteral<T> &booleanLitteral) = 0;

    /**
     * @brief Virtual method to visit a Field node.
     * 
     * @param field Reference to the Field node.
     * @return T Result of visiting the Field node.
     */
    virtual T visit(class Field<T> &field) = 0;

    /**
     * @brief Virtual method to visit a Method node.
     * 
     * @param method Reference to the Method node.
     * @return T Result of visiting the Method node.
     */
    virtual T visit(class Method<T> &method) = 0;

    /**
     * @brief Virtual method to visit a Class node.
     * 
     * @param class_ Reference to the Class node.
     * @return T Result of visiting the Class node.
     */
    virtual T visit(class Class<T> &class_) = 0;

    /**
     * @brief Virtual method to visit a Program node.
     * 
     * @param program Reference to the Program node.
     * @return T Result of visiting the Program node.
     */
    virtual T visit(class Program<T> &program) = 0;
};

/************************************/
/*        PrintVisitor class        */
/************************************/

/**
 * @brief Visitor class to print AST nodes.
 */
class PrintVisitor : public Visitor<void>
{
public:
    /**
     * @brief Constructor for PrintVisitor class.
     */
    PrintVisitor();

    // Implementations for visit methods
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