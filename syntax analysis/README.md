# vsopcompiler
INFO0085 - Compilers - VSOP Compiler Project

## Semantic Analysis

![Local Image](/images/semantic/semantic-analysis-pictures-3.PNG)

## Table of Contents
1. [Goals](#Goals)
2. [Syntax-Directed Definition](#syntax-directed-definition)
3. [Type and Scope Checking](#type-and-scope-checking)
4. [Scope](#Scope)
5. [Symbol Table](#Symbol-table)
6. [Symbol Table : Functional Implementation](#Symbol-Table-:-Functional-Implementation)
7. [Symbol Table : Imperative Implementation](#Symbol-Table-:-Imperative-Implementation)

## Goals
- [ ] Check semantic consistency of source program some language contraints cannot be captured by context-free grammar, e.g. non local/context-dependent relations. For instance 
    -> no variable is used without declaration
    -> no variable/function/class/method is defined twice
    -> number and types of arguments of a function match the definition
    -> operators are well-typed (e.g. no multiplication between number and string)
- [ ] Decorate the abstract syntax tree with additional information (e.g. types)
- [ ] Report semantic errors (last compiler phase to report errors)
- [ ] Example : \
![Local Image](/images/semantic/semantic-analysis-pictures-2.PNG)

## Syntax-Directed Definition
-[ ] **Syntax-Directed Definitions (SDD)** are a generic way to associate actions (i.e., programs) to production rules of a context-free grammar 
- [ ] Used for carrying out most semantic analyses as well as code translation
- [ ] A **Syntax-Directed Definition** associates
    -> with each grammar symbol, a set of **attributes**
    -> with each production, a set of **semantic rules** to compute the vaues of the attributes associated with the symbols appearing in the production
- [ ] A grammar with attributes and semantic rules is called an **attributed grammar**
- [ ] A parse tree augmented with the attribute values at each node is called an **annotated parse tree**

## Type and Scope Checking
- [ ] **Static Analysis**
    -> occurs at compile time (contrary to dynamic checking, occurring at run time)
    -> allow to catch errors as soon as possible and ensure that the program can be compiled
    -> can sometimes be very involved, e.g., no null pointer dereference, dead code warnings...
- [ ] **Two important checks**
    -> **Scope Checking :** checks that all variables and functions used within a given scope have been appropriately declared before use
    -> **Type Checking :** ensures that operators and functions are applied to the right number of arguments, of appropriate types
- [ ] Both checks are based on information stored in the symbol table

## Scope
- [ ] most languages offer some sort of control for scopes, restricting the visibility of an identifier to some subsection of the program
- [ ] a **scope** is typically a section of program text enclosed by basic program delimiters e.g., {} in C or Java, begin-end in Pascal
- [ ] many languages allow **nested scopes, i.e., scopes within scopes
- [ ] **global** variables and functions are available everywhere
- [ ] checking if an identifier occurrence in a program is accessiblle at the point is called **scope checking**

## Symbol Table
- [ ] The compiler keeps track of names and their binding using a **symbol table** (also called an **environment**)
- [ ] a symbol table must implement the following operations
    -> create an empty table
    -> add a binding between a name and some information
    -> lookup a name and retrieve its information
    -> enter a new scope
    -> exit a scope (and reestablish the symbol table in its state before entering the scope)
- [ ] to manage scopes, one can use a **persistent** (functional) or an **imperative** (destructively-updated) data structure

## Symbol Table : Functional Implementation
- [ ] a **persistent data structure** has the property that no operation on the structure will destroy it
- [ ] conceptually, a new modified copy is made of the data structure whenever an operation updates it
- [ ] in practice, only a small portion of the data structure is copied when a symbol table is updated, most is shared with the previous version
- [ ] **example :** lists in functional languages such as Scheme
    -> **binding :** insert the binding at the front of the list
    -> **lookup :** search the list from head to tail
    -> **entering a scope :** save the current list (a reference is made to it)
    -> **exiting  scope :** recalling the old list (the above reference is used)

## Symbol Table : Imperative Implementation
- [ ] in this **imperative approach**, only one copy of the symbol table exists
- [ ] 