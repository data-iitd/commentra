package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Function to calculate the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

// Function to calculate the least common multiple (LCM) using GCD
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Function to calculate the least common multiple (LCM) of a list of integers
func lcmList(list []int) int {
	lcm := list[0]
	for i := 1; i < len(list); i++ {
		lcm = lcm * list[i] / gcd(lcm, list[i])
	}
	return lcm
}

// Function to determine if a number is prime
func isPrime(n int) bool {
	if n == 1 {
		return false
	}
	for i := 2; i < int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

// Function to determine if a number is a palindrome
func isPalindrome(n int) bool {
	s := strconv.Itoa(n)
	return s == strings.Join(strings.Split(s, ""), "")
}

// Function to determine if a number is a triangular number
func isTriangular(n int) bool {
	return (math.Sqrt(8*float64(n)+1) - 1) == 0
}

// Function to determine if a number is a pentagonal number
func isPentagonal(n int) bool {
	return (math.Sqrt(24*float64(n)+1) + 1) == 0
}

// Function to determine if a number is a hexagonal number
func isHexagonal(n int) bool {
	return (math.Sqrt(8*float64(n)+1) + 1) == 0
}

// Function to determine if a number is a heptagonal number
func isHeptagonal(n int) bool {
	return (math.Sqrt(40*float64(n)+9) + 3) == 0
}

// Function to determine if a number is a octagonal number
func isOctagonal(n int) bool {
	return (math.Sqrt(48*float64(n)+1) + 1) == 0
}

// Function to determine if a number is a square number
func isSquare(n int) bool {
	return (math.Sqrt(float64(n)) + 0.5) == math.Floor(math.Sqrt(float64(n)))
}

// Function to determine if a number is a cube number
func isCube(n int) bool {
	return (math.Pow(float64(n), 1.0/3.0) + 0.5) == math.Floor(math.Pow(float64(n), 1.0/3.0))
}

// Function to determine if a number is a square number or a cube number
func isSquareOrCube(n int) bool {
	return isSquare(n) || isCube(n)
}

// Function to determine if a number is a perfect number
func isPerfect(n int) bool {
	sum := 0
	for i := 1; i < int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			sum += i
			if i!= n/i {
				sum += n / i
			}
		}
	}
	return sum == n
}

// Function to determine if a number is a abundant number
func isAbundant(n int) bool {
	sum := 0
	for i := 1; i < int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			sum += i
			if i!= n/i {
				sum += n / i
			}
		}
	}
	return sum > n
}

// Function to determine if a number is a deficient number
func isDeficient(n int) bool {
	return!isAbundant(n) &&!isPerfect(n)
}

// Function to determine if a number is a amicable number
func isAmicable(n int) bool {
	sum := 0
	for i := 1; i < int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			sum += i
			if i!= n/i {
				sum += n / i
			}
		}
	}
	return sum == n && n!= sum
}

// Function to determine if a number is a abundant number or a perfect number
func isAbundantOrPerfect(n int) bool {
	return isAbundant(n) || isPerfect(n)
}

// Function to determine if a number is a deficient number or a perfect number
func isDeficientOrPerfect(n int) bool {
	return isDeficient(n) || isPerfect(n)
}

// Function to determine if a number is a abundant number or a perfect number or a deficient number
func isAbundantOrPerfectOrDeficient(n int) bool {
	return isAbundant(n) || isPerfect(n) || isDeficient(n)
}

// Function to determine if a number is a triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number
func isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficient(n int) bool {
	return isTriangular(n) || isPentagonal(n) || isHexagonal(n) || isHeptagonal(n) || isOctagonal(n) || isSquare(n) || isCube(n) || isSquareOrCube(n) || isPerfect(n) || isAbundant(n) || isDeficient(n) || isAmicable(n) || isAbundantOrPerfect(n) || isDeficientOrPerfect(n) || isAbundantOrPerfectOrDeficient(n)
}

// Function to determine if a number is a triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, and prime number
func isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrime(n int) bool {
	return isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficient(n) && isPrime(n)
}

// Function to determine if a number is a triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, and palindrome number
func isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindrome(n int) bool {
	return isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrime(n) && isPalindrome(n)
}

// Function to determine if a number is a triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, palindrome number, and triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, palindrome number
func isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindromeOrTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindrome(n int) bool {
	return isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindromeOrTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindrome(n)
}

// Function to determine if a number is a triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, palindrome number, triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, palindrome number, and triangular number, pentagonal number, hexagonal number, heptagonal number, octagonal number, square number, cube number, square number or cube number, perfect number, abundant number, deficient number, amicable number, abundant number or perfect number, deficient number or perfect number, abundant number or perfect number or deficient number, prime number, palindrome number
func isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindromeOrTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindromeOrTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindrome(n int) bool {
	return isTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeOrPalindromeOrTriangularOrPentagonalOrHexagonalOrHeptagonalOrOctagonalOrSquareOrCubeOrSquareOrCubeOrPerfectOrAbundantOrDeficientOrAmicableOrAbundantOrPerfectOrDeficientOrAbundantOrPerfectOrDeficientOrPrimeO