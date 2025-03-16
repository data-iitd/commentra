<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Function to check if a number is prime
func isPrime(num int) bool {
    if num < 2 { // 2 is the smallest prime number
        return false
    } else if num == 2 { // 2 is a prime number
        return true
    } else if num%2 == 0 { // Even numbers greater than 2 are not prime
        return false
    }

    sqrtNum := int(math.Sqrt(float64(num))) // Calculate square root of number
    for i := 3; i <= sqrtNum; i += 2 { // Iterate through odd numbers up to square root
        if num%i == 0 { // If number is divisible by current odd number
            return false // It's not a prime number
        }
    }

    // If number is not divisible by any odd number up to its square root, it's a prime number
    return true
}

// Function to calculate the number of combinations of n items taken r at a time modulo m
func combination_mod(n, r, m int) int {
    if r > n-r { // Adjust r if it's greater than the difference between n and r
        r = n - r
    }
    if r == 0 { // Base case: combination of 0 items is 1
        return 1
    }
    a := 1
    for i := 0; i < r; i++ { // Calculate first term
<<<<<<< HEAD
        a = a * (n - i) % m
=======
        a = a * (n-i) % m
>>>>>>> 98c87cb78a (data updated)
    }
    b := pow(fact_mod(r, m), m-2, m) // Calculate second term
    return (a * b) % m
}

// Function to calculate x^n modulo m using repeated squaring method
func pow(x, n, m int) int {
    res := 1
    for n > 0 { // While n is not zero
        if n&1 == 1 { // If n is odd, multiply x with result and reduce modulo m
            res = (res * x) % m
        }
        x = (x * x) % m // Square x and reduce modulo m
        n >>= 1 // Divide n by 2
    }
    return res
}

// Function to calculate factorial modulo m
func fact_mod(n, m int) int {
    f := 1
    for i := 2; i <= n; i++ { // Iterate through numbers from 2 to n
        f = f * i % m
    }
    return f
}

// Function to calculate the greatest common divisor of two numbers
func gcd(a, b int) int {
    if b == 0 { // Base case: greatest common divisor of two numbers is the smaller number
        return a
    }
    return gcd(b, a%b) // Recursive call to calculate greatest common divisor
}

// Function to calculate the least common multiple of two numbers
func lcm(a, b int) int {
    return a / gcd(a, b) * b // Find least common multiple by multiplying greatest common divisor and smaller number
}

// Function to find maximum of three numbers
func Max(a, b, c int) int {
    temp := max(a, b) // Find maximum of two numbers
    return max(temp, c) // Compare maximum with third number and return the result
}

// Function to find minimum of three numbers
func Min(a, b, c int) int {
    temp := min(a, b) // Find minimum of two numbers
    return min(temp, c) // Compare minimum with third number and return the result
}

// Function to check if a number is an integer
func integer(num float64) bool {
    return math.Floor(num) == num
}

// Function to calculate the number of divisors of a number
func yakusu(n int) int {
    cnt := 0 // Initialize divisor count
    for i := 1; i*i <= n; i++ { // Iterate through divisors up to square root of n
        if n%i == 0 { // If n is divisible by current divisor
            cnt++ // Increment divisor count
            if i*i!= n { // If n has more than one divisor, increment count
                cnt++
            }
        }
    }
    return cnt // Return divisor count
}

// Function to calculate factorial of a number
func fact(num int) int {
    if num == 0 { // Base case: factorial of 0 is 1
        return 1
    }
    return num * fact(num-1) // Recursive call to calculate factorial
}

// Function to reverse a string
func rev(s string) string {
    t := s // Create a copy of string s
    for i := 0; i < len(s)/2; i++ { // Iterate through string s
        t[i], t[len(s)-1-i] = t[len(s)-1-i], t[i] // Swap characters at i and len(s)-1-i
    }
    return t
}

// Function to check if a string is a palindrome
func palindrome(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome2(s string) bool {
    return strings.EqualFold(s, rev(s)) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome3(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome4(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome5(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome6(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome7(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome8(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome9(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome10(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome11(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome12(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome13(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome14(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome15(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome16(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome17(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome18(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome19(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome20(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome21(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome22(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome23(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome24(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome25(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome26(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome27(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome28(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome29(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome30(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome31(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome32(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome33(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome34(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome35(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome36(s string) bool {
    return s == rev(s) // Check if string s is equal to its reversed version
}

// Function to check if a string is a palindrome
func palindrome37(s string) bool {
<<<<<<< HEAD
    return s == rev(s) // Check if string s is equal to its reversed ve
=======
    return s == rev(s) // Check if string s is equal to its reversed vers
>>>>>>> 98c87cb78a (data updated)
