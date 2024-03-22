# vsopcompiler
INFO0085 - Compilers - VSOP Compiler Project

## Lexical Analysis

![Local Image](/images/lexical/scanning.PNG)

## Table of Contents
1. [Goals](#Goals)

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