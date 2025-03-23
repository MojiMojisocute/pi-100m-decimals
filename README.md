# Pi Calculator

This C++ program calculates π (Pi) to an arbitrary number of decimal places using the Gauss-Legendre algorithm and the GNU Multiple Precision Arithmetic Library (GMP).

## Mathematical Background

The Gauss-Legendre algorithm is an iterative method that converges quadratically to π. The algorithm uses the arithmetic-geometric mean and is represented by the following equations:

### Algorithm

Initialize:
- $a_0 = 1$
- $b_0 = \frac{1}{\sqrt{2}}$
- $t_0 = \frac{1}{4}$
- $p_0 = 1$

For each iteration $i$:
- $a_{i+1} = \frac{a_i + b_i}{2}$
- $b_{i+1} = \sqrt{a_i \cdot b_i}$
- $t_{i+1} = t_i - p_i \cdot (a_i - a_{i+1})^2$
- $p_{i+1} = 2 \cdot p_i$

After $n$ iterations, π is approximated by:
- $\pi \approx \frac{(a_n + b_n)^2}{4 \cdot t_n}$

In this implementation, the algorithm runs for 20 iterations, which is sufficient for high precision.

## Prerequisites

To compile and run this program, you need:

- A C++ compiler (e.g., g++)
- The GNU Multiple Precision Arithmetic Library (GMP)

### Installation

#### Ubuntu/Debian:
```bash
sudo apt-get install libgmp-dev
```

#### macOS:
```bash
brew install gmp
```

#### Windows:
For Windows, consider using MSYS2, WSL, or pre-compiled libraries.

## Compilation

Compile the program with:

```bash
g++ -o compute_pi compute_pi.cpp -lgmp -lgmpxx
```

## Usage

1. Run the compiled program:
   ```bash
   ./compute_pi
   ```

2. When prompted, enter the desired number of decimal places.

3. The result will be written to a file named `pi_output.txt` in the current directory.

## Example

```
Enter the number of decimal places for Pi: 
```

This will calculate π to 1000 decimal places and save the result to `pi_output.txt`.

## Performance Considerations

- The computation time increases with the number of decimal places requested.
- The program uses approximately 3.32193 bits of precision per decimal digit.
- Memory usage scales linearly with the requested precision.

## Implementation Notes

- The program uses the GMP library for high-precision arithmetic operations.
- The computation precision is set based on the requested decimal places.
- After computation, the result is written to a file rather than displayed in the console, which is more practical for very large numbers of digits.
