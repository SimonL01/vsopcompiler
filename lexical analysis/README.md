# vsopcompiler
INFO0085 - Compilers - VSOP Compiler Project

## Lexical Analysis

![Local Image](/images/lexical/scanning.PNG)

## Table of Contents
1. [Goals](#Goals)
2. [Definitions](#Definitions)
3. [Designing a Lexical Analysis](#Designing-a-lexical-analysis)
4. [Regular Expressions](#regular-expressions)
5. [Algorithms for Lexical Analysis](#algorithms-for-lexical-analysis)

## Goals
- [ ] Split the character stream into meaningful sequences called lexemes
- [ ] Label each lexeme with a token that is passed to the parser (syntax analysis)
- [ ] Remove non-significant blanks and comments
- [ ] Optional : update the symbol tables with all identifiers (and numbers)
- [ ] That is, be the interface between the source program and the parser
- [ ] Example : \
![Local Image](/images/lexical/scanning-eg.PNG)

## Definitions
- [ ] A token is a (**class**, attribute) pair. Attribute might be multi-valued. \
Examples : (**id**, i), (**operator**, +)
- [ ] A pattern describes the set of possible character strings for the lexemes of the token. \
Examples : \
    -> a string of letters and digits starting with a letter \
    -> {<, >, &le;, &ge;, ==} \
    -> )
- [ ] A lexeme for a token is a string that matches the pattern for the token. \
    Examples : i, <, ) in the following program
    > while (i < n) \
    &nbsp; &nbsp; &nbsp; i++;

## Designing a Lexical Analysis
1. Define the set of tokens (depends on the source language, one token for each keyword, a.k.a. reserved word, one token for each "punctuation" symbol, an **identifier** token, tokens for operators, constants such as numbers or literal strings). Attributes need to encode the lexeme corresponding to the token when necessary, a pointer to the symbol table for identifiers, constant value for constants etc.
2. Define a pattern for each token (i.e., the set of lexemes associated with each token). A lexeme being a string, a pattern is actually a **language**. Patterns are typically defined through **regular expressions** (that define regular languages).
3. Design an algorithm to cut the source program into lexemes and outputs the tokens

## Regular Expressions
- [ ] An **alphabet** $\Sigma$ is a set of characters. \
Example : $\Sigma$ = {a, b}
- [ ] A **string** over $\Sigma$ is a finite sequence of elements from $\Sigma$. \
Example : aabba
- [ ] A **language** is a set of strings. \
Example : $L$ = {a, b, abab, babbba}
- [ ] A **regular language** is a language that can be defined by a regular expression
- [ ] Any character $a \in \Sigma$ is a regular expression
- [ ] $\varepsilon$ is a regular expression
- [ ] If $R_1$ and $R_2$ are regular expressions, then \
    -> $R_1R_2$ is a regular expression (Concatenation) \
    -> $R_1 | R_2$ (= $R_1 \cup R_2$) is a regular expression \
    -> $R_1^*$ is a regular expression (Kleene closure) \
    -> ($R_1$) is a regular expression \
Example : a regular expression for even numbers : \
(+ | - | $\varepsilon$)(0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9)*(0 | 2 | 4 | 6 | 8)
- [ ] Usual definitions \
    < letter > -> 1 | B | ... | Z | a | b | ... | z \
    < digit > -> 0 | 1 | ... | 9 \
    < id > -> < letter > (< letter > | < digit >)*
- [ ] One or more instances : $R^+$ = $RR^*$
- [ ] Zero or one instance : $R? = R | \varepsilon$
- [ ] Character classes : \
    [ abc ] -> a | b | c
    [ a - z ] -> a | b | ... | z
    [ 0 - 9 ] -> 0 | 1 | ... | 9
    [ ^a ] -> all letters but a

## Algorithms for Lexical Analysis
Given token definitions in regular expressions, how can one build a lexical analyzer ?
- [ ] Regular expressions are equivalent to **finite automata**, deterministic (DFA) or non-deterministic (NFA)
- [ ] Finite automata are easily turned into computer programs
- [ ] Two methods :
1. Convert the regular expressions to a NFA and simulate the NFA
2. Convert the regukar expressions to a NFA, convert the NFA to a DFA and simulate the DFA
- [ ] Having a separate regular expression for each keyword is not very efficient. In practice, only one regular expression stands for both keywords and identifiers. A hash table contains all keywords. Once an identifier/keyword is read, a table lookup decides if it is an identifier or a keyword. This reduces drastically the size of the DFA. Adding a keyword requires only to add one entry in the hash table.