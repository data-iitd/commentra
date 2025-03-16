
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Taking the number of elements N and the number of queries K as input
	N, K := readTwoInt()

	// Creating an empty list to store positive numbers and another empty list to store negative numbers
	lst := make([]int, N)
	lst_p := make([]int, 0)
	lst_m := make([]int, 0)

	// Iterating through the list to find positive and negative numbers
	for i := 0; i < N; i++ {
		// If the number is zero, decrement the number of queries K
		if lst[i] == 0 {
			K--
		}
		// If the number is positive, add it to the list of positive numbers
		if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		}
		// If the number is negative, add it to the list of negative numbers
		if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}

	// Initializing variables p and m to 0 and setting the initial values of x and y
	p, m, x, y := 0, 0, 0, len(lst_m)-1
	lastx := len(lst_p)
	lasty := len(lst_m)

	// Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
	check := func(k int) int {
		// Initializing the answer as a large number
		ans := 1000000000

		// Iterating through all possible combinations of taking elements from positive and negative lists
		for j := 0; j <= lastx && k-j <= lasty; j++ {
			// If j is 0, then p is initialized to 0
			if j == 0 {
				p = 0
			} else {
				// If j is not 0, then p is the last element of the list of positive numbers
				p = lst_p[j-1]
			}

			// If k - j is 0, then m is initialized to 0
			if k-j == 0 {
				m = 0
			} else {
				// If k - j is not 0, then m is the last element of the list of negative numbers
				m = lst_m[lasty-(k-j)]
			}

			// Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
			ans = min(ans, 2*p+abs(m), p+2*abs(m))
		}

		// Returning the answer
		return ans
	}

	// Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
	fmt.Println(check(K))
}

// Function to read two integers from the input
func readTwoInt() (int, int) {
	// Creating a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()

	// Splitting the input string into two integers
	n1, _ := strconv.Atoi(s[:len(s)/2])
	n2, _ := strconv.Atoi(s[len(s)/2:])

	// Returning the two integers
	return n1, n2
}

// Function to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Function to calculate the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to calculate the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to calculate the factorial of an integer
func factorial(n int) int {
	if n == 0 {
		return 1
	}
	return n * factorial(n-1)
}

// Function to calculate the binomial coefficient of two integers
func binomial(n, k int) int {
	return factorial(n) / (factorial(k) * factorial(n-k))
}

// Function to calculate the greatest common divisor of two integers
func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple of two integers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Function to calculate the sum of the first n integers
func sum(n int) int {
	return n * (n + 1) / 2
}

// Function to calculate the sum of the squares of the first n integers
func sum2(n int) int {
	return n * (n + 1) * (2*n + 1) / 6
}

// Function to calculate the sum of the cubes of the first n integers
func sum3(n int) int {
	return n * (n + 1) / 2 * (n + 1)
}

// Function to calculate the sum of the fourth powers of the first n integers
func sum4(n int) int {
	return n * (n + 1) / 2 * (2*n + 1) * (3*n*n + 3*n - 1) / 30
}

// Function to calculate the sum of the fifth powers of the first n integers
func sum5(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) / 5
}

// Function to calculate the sum of the sixth powers of the first n integers
func sum6(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) / 42
}

// Function to calculate the sum of the seventh powers of the first n integers
func sum7(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) / 5040
}

// Function to calculate the sum of the eighth powers of the first n integers
func sum8(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) / 40320
}

// Function to calculate the sum of the ninth powers of the first n integers
func sum9(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) * (11*n*n*n*n*n*n + 99*n*n*n*n*n + 385*n*n*n*n + 945*n*n*n + 1001*n*n - 945*n + 143) / 362880
}

// Function to calculate the sum of the tenth powers of the first n integers
func sum10(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) * (11*n*n*n*n*n*n + 99*n*n*n*n*n + 385*n*n*n*n + 945*n*n*n + 1001*n*n - 945*n + 143) * (13*n*n*n*n*n*n*n + 182*n*n*n*n*n*n + 1386*n*n*n*n*n + 5005*n*n*n*n + 10010*n*n*n + 10010*n*n - 1386*n + 210) / 3628800
}

// Function to calculate the sum of the first n integers raised to the power of 11
func sum11(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) * (11*n*n*n*n*n*n + 99*n*n*n*n*n + 385*n*n*n*n + 945*n*n*n + 1001*n*n - 945*n + 143) * (13*n*n*n*n*n*n*n + 182*n*n*n*n*n*n + 1386*n*n*n*n*n + 5005*n*n*n*n + 10010*n*n*n + 10010*n*n - 1386*n + 210) * (15*n*n*n*n*n*n*n*n + 286*n*n*n*n*n*n*n + 3003*n*n*n*n*n*n + 17570*n*n*n*n*n + 55445*n*n*n*n + 100100*n*n*n + 100100*n*n - 17570*n + 3465) / 39916800
}

// Function to calculate the sum of the first n integers raised to the power of 12
func sum12(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) * (11*n*n*n*n*n*n + 99*n*n*n*n*n + 385*n*n*n*n + 945*n*n*n + 1001*n*n - 945*n + 143) * (13*n*n*n*n*n*n*n + 182*n*n*n*n*n*n + 1386*n*n*n*n*n + 5005*n*n*n*n + 10010*n*n*n + 10010*n*n - 1386*n + 210) * (15*n*n*n*n*n*n*n*n + 286*n*n*n*n*n*n*n + 3003*n*n*n*n*n*n + 17570*n*n*n*n*n + 55445*n*n*n*n + 100100*n*n*n + 100100*n*n - 17570*n + 3465) * (17*n*n*n*n*n*n*n*n*n + 413*n*n*n*n*n*n*n*n + 6006*n*n*n*n*n*n*n + 48048*n*n*n*n*n*n + 223090*n*n*n*n*n + 64350*n*n*n*n + 1001000*n*n*n + 1001000*n*n - 223090*n + 55440) / 479001600
}

// Function to calculate the sum of the first n integers raised to the power of 13
func sum13(n int) int {
	return n * (n + 1) / 2 * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1) * (5*n*n*n + 10*n*n + 10*n - 1) * (7*n*n*n*n + 21*n*n*n + 35*n*n - 35*n + 6) * (9*n*n*n*n*n + 45*n*n*n*n + 105*n*n*n + 105*n*n - 21*n + 1) * (11*n*n*n*n*n*n + 99*n*n*n*n*n + 385*n*n*n*n + 945*n*n*n + 1001*n*n - 945*n + 143) * (13*n*n*n*n*n*n*n + 182*n*n*n*n*n*n + 1386*n*n*n*n*n + 5005*n*n*n*n + 10010*n*n*n + 10010*n*n - 1386*n + 210) * (15*n*n*n*n*n*n*n*n + 286*n*n*n*n*n + 3003*n*n*n*n*n + 17570*n*n*n + 55445*n*n*n + 100100*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*n + 1001000*n*n*