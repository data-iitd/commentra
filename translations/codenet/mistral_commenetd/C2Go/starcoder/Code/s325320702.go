
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

// Include necessary standard libraries

// Define custom data types

// Macros for repetition

// Constants and definitions

// Function to swap two variables

// Function to read an integer from the standard input

// Function to find the maximum of two numbers

// Function to find the minimum of two numbers

// Function to find the minimum of three numbers

// Function to find the maximum of three numbers

// Function to find the minimum number in an array

// Function to find the maximum number in an array

// Function to calculate a^b

// Function to calculate a^b (double version)

// Function to find the greatest common divisor of two numbers

// Function to find the least common multiple of two numbers

// Function to calculate n % MOD1

// Function to calculate n % p

// Function to convert a substring of a string into a number

// Function to calculate the number of digits in a number

// Function to calculate the base representation of a number

// Function to check if a number is within the range of an array

// Function to check if a pair of coordinates is within the range of a rectangle

// Function to find the lowest index i such that a[i] = val
// If type is less than 3, then am < val, otherwise am <= val

// Function to find the highest index i such that a[i] = val
// If type is less than 3, then am <= val, otherwise am < val

// Comparison function for lower_bound
// If type is 1, then a == b, otherwise a < b (type = 2) or a < b (type = 3)

// Comparison function for upper_bound
// If type is 1, then a == b, otherwise a <= b (type = 2) or a < b (type = 3)

// Binary search function for finding the lowest index i such that a[i] = val
// If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)

// Binary search function for finding the highest index i such that a[i] = val
// If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)

// Function to find the number of occurrences of x in the subarray a[l..r]

// Function to find the prime factorization of n
// new_common_plus can be 1 (common factor), 2 (common factor and its power), or 0 (no common factor)

// Function to check if n is prime

// Function to calculate the multiplicative inverse of x modulo mod
// is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)

// Function to calculate the inverse of x modulo mod
// is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)

// Function to calculate the multiplicative function of x modulo mod

// Function to calculate nCk modulo mod

// Function to calculate r^n modulo mod

// Function to calculate the product of two numbers modulo mod

// Function to calculate the product of three numbers modulo mod

// Function to calculate the product of four numbers modulo mod

// Function to calculate the product of five numbers modulo mod

// Function to find the lowest and highest indices of a value in an array

// Function to find the number of occurrences of a value in an array

// Function to calculate the number of unique elements in an array or a string

// Global variables and constants

func main() {
    // Main function

    var l, r, d int
    var ans int

    fmt.Scanf("%d", &l)
    fmt.Scanf("%d", &r)
    fmt.Scanf("%d", &d)

    for i := l; i <= r; i++ {
        if i%d == 0 {
            ans++
        }
    }

    fmt.Printf("%d\n", ans)
}

