# Arbitrary Precision Arithmetic (BigInteger)

A high-performance C++ library for performing arithmetic on integers of arbitrary size. This project implements a **BigInteger ADT** using a doubly-linked list of long integers, where each node stores 9 decimal digits.

## Technical Implementation
- **Base-10^9 Representation**: Digits are stored in groups of 9 to maximize the efficiency of 64-bit integer arithmetic while preventing overflow during intermediate steps.
- **Complexity Operations**:
  - **Addition/Subtraction**: $O(n)$ where $n$ is the number of digits.
  - **Multiplication**: $O(n \cdot m)$ using a vector-based scalar multiplication and shift algorithm.
- **Memory Management**: Utilizes a custom `List` ADT for dynamic memory allocation and efficient traversal.

## Features
- Overloaded operators for intuitive syntax: `+`, `-`, `*`, `+=`, `-=`, `*=`, `<<`, and comparison operators (`==`, `<`, etc.).
- Robust string-to-BigInteger parsing with error handling for non-numeric input.
- Efficient normalization logic to handle carries and borrows across list nodes.

## Building and Running
### Build
```bash
make
```

## Usage
The Arithmetic client reads two BigIntegers from a file and outputs the results of several operations.
``` bash
./Arithmetic <input_file> <output_file>
```

## Performance Note
This implementation uses a standard $O(n^2)$ multiplication algorithm. For massive calculations (thousands of digits), performance is optimized by minimizing string/numeric conversions during normalization steps.
