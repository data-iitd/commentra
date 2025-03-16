
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
func nextStr() string {
	sc.Scan()
	return sc.Text()
}

// nextInt reads the next integer from input
func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// maxInt returns the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// minInt returns the minimum of two integers
func minInt(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

// absInt returns the absolute value of an integer
func absInt(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// absFloat64 returns the absolute value of a float64
func absFloat64(a float64) float64 {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// maxFloat64 returns the maximum of two float64 values
func maxFloat64(a, b float64) float64 {
	if a > b {
		return a
	} else {
		return b
	}
}

// minFloat64 returns the minimum of two float64 values
func minFloat64(a, b float64) float64 {
	if a > b {
		return b
	} else {
		return a
	}
}

// str2Int converts a string to an integer
func str2Int(s string) int {
	n, _ := strconv.Atoi(s) // Ignore error for simplicity
	return n
}

// reverse returns the reversed string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// powInt calculates p raised to the power of q
func powInt(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// isPrime checks if a number is prime
func isPrime(x int) bool {
	if x == 1 {
		return false
	}
	if x == 2 {
		return true
	}
	if x%2 == 0 {
		return false
	}

	b := true
	rootx := int(math.Sqrt(float64(x)))
	i := 3
	for i <= rootx {
		if x%i == 0 {
			b = false
			break
		}
		i += 2
	}
	return b
}

// PrimeFactors returns the prime factors of a number
func PrimeFactors(n int) (pfs []int) {
	// Get the number of 2s that divide n
	for n%2 == 0 {
		pfs = append(pfs, 2)
		n = n / 2
	}

	// n must be odd at this point, so we can skip one element
	for i := 3; i*i <= n; i = i + 2 {
		// while i divides n, append i and divide n
		for n%i == 0 {
			pfs = append(pfs, i)
			n = n / i
		}
	}

	// Handle the case when n is a prime number greater than 2
	if n > 2 {
		pfs = append(pfs, n)
	}

	return
}

// PrimeFactorsMap returns a map of prime factors and their counts
func PrimeFactorsMap(n int) map[int]int {
	pfs := map[int]int{}
	// Get the number of 2s that divide n
	for n%2 == 0 {
		if _, ok := pfs[2]; ok {
			pfs[2]++
		} else {
			pfs[2] = 1
		}
		n = n / 2
	}

	// n must be odd at this point, so we can skip one element
	for i := 3; i*i <= n; i = i + 2 {
		// while i divides n, append i and divide n
		for n%i == 0 {
			if _, ok := pfs[i]; ok {
				pfs[i]++
			} else {
				pfs[i] = 1
			}
			n = n / i
		}
	}

	// Handle the case when n is a prime number greater than 2
	if n > 2 {
		if _, ok := pfs[n]; ok {
			pfs[n]++
		} else {
			pfs[n] = 1
		}
	}

	return pfs
}

// sumInts returns the sum of a slice of integers
func sumInts(x []int) int {
	total := 0
	for _, v := range x {
		total += v
	}
	return total
}

// gcd calculates the greatest common divisor of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// lcm calculates the least common multiple of two integers
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// Main function
const (
	initialBufSize = 10000 // Initial buffer size for input
	maxBufSize     = 1000000 // Maximum buffer size for input
	mod            = 1e9 + 7 // Modulus value
)

var (
	// Scanner for reading input
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		return sc
	}()
)

func main() {
	sc.Split(bufio.ScanWords) // Split input by words
	// Read the number of 'S' and 'c'
	N, M := nextInt(), nextInt()
	tmp := minInt(N, M/2) // Calculate the minimum of N and half of M
	ans := 0
	ans += tmp // Add the temporary value to the answer
	N -= tmp // Decrease N by the temporary value
	M -= tmp * 2 // Decrease M by twice the temporary value
	// Output the final answer, which includes the remaining M divided by 4
	fmt.Println(ans + M/4)
}

# Python:

# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
func nextStr() string {
	sc.Scan()
	return sc.Text()
}

// nextInt reads the next integer from input
func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// maxInt returns the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// minInt returns the minimum of two integers
func minInt(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

// absInt returns the absolute value of an integer
func absInt(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// absFloat64 returns the absolute value of a float64
func absFloat64(a float64) float64 {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// maxFloat64 returns the maximum of two float64 values
func maxFloat64(a, b float64) float64 {
	if a > b {
		return a
	} else {
		return b
	}
}

// minFloat64 returns the minimum of two float64 values
func minFloat64(a, b float64) float64 {
	if a > b {
		return b
	} else {
		return a
	}
}

// str2Int converts a string to an integer
func str2Int(s string) int {
	n, _ := strconv.Atoi(s) // Ignore error for simplicity
	return n
}

// reverse returns the reversed string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// powInt calculates p raised to the power of q
func powInt(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// isPrime checks if a number is prime
func isPrime(x int) bool {
	if x == 1 {
		return false
	}
	if x == 2 {
		return true
	}
	if x%2 == 0 {
		return false
	}

	b := true
	rootx := int(math.Sqrt(float64(x)))
	i := 3
	for i <= rootx {
		if x%i == 0 {
			b = false
			break
		}
		i += 2
	}
	return b
}

// PrimeFactors returns the prime factors of a number
func PrimeFactors(n int) (pfs []int) {
	// Get the number of 2s that divide n
	for n%2 == 0 {
		pfs = append(pfs, 2)
		n = n / 2
	}

	// n must be odd at this point, so we can skip one element
	for i := 3; i*i <= n; i = i + 2 {
		// while i divides n, append i and divide n
		for n%i == 0 {
			pfs = append(pfs, i)
			n = n / i
		}
	}

	// Handle the case when n is a prime number greater than 2
	if n > 2 {
		pfs = append(pfs, n)
	}

	return
}

// PrimeFactorsMap returns a map of prime factors and their counts
func PrimeFactorsMap(n int) map[int]int {
	pfs := map[int]int{}
	// Get the number of 2s that divide n
	for n%2 == 0 {
		if _, ok := pfs[2]; ok {
			pfs[2]++
		} else {
			pfs[2] = 1
		}
		n = n / 2
	}

	// n must be odd at this point, so we can skip one element
	for i := 3; i*i <= n; i = i + 2 {
		// while i divides n, append i and divide n
		for n%i == 0 {
			if _, ok := pfs[i]; ok {
				pfs[i]++
			} else {
				pfs[i] = 1
			}
			n = n / i
		}
	}

	// Handle the case when n is a prime number greater than 2
	if n > 2 {
		if _, ok := pfs[n]; ok {
			pfs[n]++
		} else {
			pfs[n] = 1
		}
	}

	return pfs
}

// sumInts returns the sum of a slice of integers
func sumInts(x []int) int {
	total := 0
	for _, v := range x {
		total += v
	}
	return total
}

// gcd calculates the greatest common divisor of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// lcm calculates the least common multiple of two integers
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// Main function
const (
	initialBufSize = 10000 // Initial buffer size for input
	maxBufSize     = 1000000 // Maximum buffer size for input
	mod            = 1e9 + 7 // Modulus value
)

var (
	// Scanner for reading input
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		return sc
	}()
)

func main() {
	sc.Split(bufio.ScanWords) // Split input by words
	// Read the number of 'S' and 'c'
	N, M := nextInt(), nextInt()
	tmp := minInt(N, M/2) // Calculate the minimum of N and half of M
	ans := 0
	ans += tmp // Add the temporary value to the answer
	N -= tmp // Decrease N by the temporary value
	M -= tmp * 2 // Decrease M by twice the temporary value
	// Output the final answer, which includes the remaining M divided by 4
	fmt.Println(ans + M/4)
}

# Python:

# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
func nextStr() string {
	sc.Scan()
	return sc.Text()
}

// nextInt reads the next integer from input
func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// maxInt returns the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// minInt returns the minimum of two integers
func minInt(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

// absInt returns the absolute value of an integer
func absInt(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// absFloat64 returns the absolute value of a float64
func absFloat64(a float64) float64 {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// maxFloat64 returns the maximum of two float64 values
func maxFloat64(a, b float64) float64 {
	if a > b {
		return a
	} else {
		return b
	}
}

// minFloat64 re