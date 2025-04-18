# Calculator Language Syntax

This document describes the syntax of the language supported by the calculator compiler, including operators, declarations, data structures, and mathematical functions.

## Data Types
- **Numbers**: integers, real numbers, and complex numbers (e.g., `3`, `4.5`, `2 + 3i`)
- **Vectors**: 
  - Row vector: `[1, 2, 3]`
  - Column vector: `[1; 2; 3]`
- **Matrices**: `[1, 2; 3, 4]`

## Declarations
- Assignment using `=`:
  ```
  col = [1; 2; 3];
  row = [1, 2, 3];
  matrix = [1, 2; 3, 4];
  x = 3 + 4i;
  ```

## Supported Operators

### Arithmetic
- `+` : addition
- `-` : subtraction
- `*` : multiplication
- `/` : division
- `%` : integer division remainder
- `^` : exponentiation

### Logical and Bitwise
- `&` : conjunction (AND)
- `~` : bitwise negation
- `<` , `>` , '>=' , '<=' , '==' , '!=': comparison

## Built-in Mathematical Functions

### Number Functions
- `abs(x)` : absolute value
- `sqrt(x)` : square root
- `log(x)` : natural logarithm

### Trigonometric Functions
- `sin(x)` : sine
- `cos(x)` : cosine
- `asin(x)` : arcsine (inverse of sine)

### Matrix and Vector Operators
- The operations `+`, `-`, `*`, `/`, `^` also work with vectors and matrices, following linear algebra rules.
- Special functions such as `det()`, `inv()`, `transp()` (transpose) are available.

## Comments
- Comments start with `//` and go to the end of the line.
  ```
  // this is a comment
  x = 4 + 3; // inline comment
  ```

---

# Calculator Features

This document details the functionalities implemented in the compiler/calculator, including support for mathematical expressions, matrices, complex numbers, and more.

## General Features
- Evaluates mathematical expressions with correct operator precedence
- Supports global-scope variables
- Evaluates complex expressions with nested functions

## Vectors and Matrices
- Supports row and column vectors
- Matrices of arbitrary dimensions
- Operations: addition, subtraction, multiplication, exponentiation
- Functions: 
  - `det(M)` : determinant
  - `inv(M)` : inverse
  - `transp(M)` : transpose

## Complex Numbers
- Intuitive syntax: `3 + 4i`
- Supports arithmetic operations with complex numbers
- Integrated with functions like `abs`, `sqrt`, etc.

## Extensibility
- The system allows easy addition of new mathematical functions
- Can be extended to work with graphs, integrals, derivatives, etc.

---

Gonçalo Branquinho
