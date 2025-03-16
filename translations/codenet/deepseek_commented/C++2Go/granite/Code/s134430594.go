
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Structure to store the left, right, and value of a ban
type Ban struct {
	l, r, val int
}

// Namespace for sparse table operations
var (
	lim = 20
	n   = 2e5 + 7
	mn  = make([][]int, lim)
	pw  = make([]int, n)
)

func init() {
	for i := 0; i < lim; i++ {
		mn[i] = make([]int, n)
	}
	pw[1] = 0
	for i := 2; i < n; i++ {
		pw[i] = pw[i/2] + 1
	}
}

// Query the sparse table for the minimum value in the range [l, r)
func get(l, r int) int {
	r++
	p := pw[r - l]
	return min(mn[p][l], mn[p][r-(1<<p)])
}

// Main function to execute the program
func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		dl := make([]int, n)
		for i := 0; i < n; i++ {
			if A[i] > i {
				buf.WriteString("-1\n")
				continue
			}
			dl[i] = i - A[i]
		}
		ans := 0
		var bans []Ban
		for i := 0; i < n; i++ {
			r := i
			for r+1 < n && A[r]+1 == A[r+1] {
				r++
			}
			ans += A[r]
			i = r
			bans = append(bans, Ban{r - A[r], r, r - A[r]})
		}
		for i := 0; i < n; i++ {
			mn[0][i] = dl[i]
		}
		for i := 0; i+1 < lim; i++ {
			for j := 0; j+(1<<i) <= n; j++ {
				mn[i+1][j] = max(mn[i][j], mn[i][j+(1<<i)])
			}
		}
		for _, ban := range bans {
			if get(ban.l, ban.r) > ban.val {
				buf.WriteString("-1\n")
				continue
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", ans))
	}

	fmt.Print(buf.String())
}

// Function to read an integer from the input
func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

// Function to read a string from the input
func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

// Function to read a single integer from the input
func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

// Function to read an array of integers from the input
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

// Function to read a matrix of integers from the input
func readMat(reader *bufio.Reader, n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readNNums(reader, m)
	}
	return res
}

// Function to calculate the minimum value in the range [l, r)
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

// Function to calculate the maximum value in the range [l, r)
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

// Function to calculate the power of 2
func pow(x int, n int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res *= x
		}
		x *= x
		n >>= 1
	}
	return res
}

// Function to calculate the factorial of a number
func factorial(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

// Function to calculate the binomial coefficient
func binom(n int, k int) int {
	return factorial(n) / (factorial(k) * factorial(n-k))
}

// Function to calculate the number of combinations with repetition
func combinationWithRep(n int, k int) int {
	return factorial(n+k-1) / (factorial(k) * factorial(n-1))
}

// Function to calculate the number of permutations with repetition
func permutationWithRep(n int, k int) int {
	return factorial(n) / factorial(n-k)
}

// Function to calculate the number of permutations
func permutation(n int, k int) int {
	return factorial(n) / factorial(n-k)
}

// Function to calculate the number of combinations
func combination(n int, k int) int {
	return factorial(n) / (factorial(k) * factorial(n-k))
}

// Function to calculate the number of divisors of a number
func numDivisors(n int) int {
	var res int
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			if n/i == i {
				res++
			} else {
				res += 2
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number
func sumDivisors(n int) int {
	var res int
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			if n/i == i {
				res += i
			} else {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the greatest common divisor of two numbers
func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple of two numbers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Function to calculate the number of prime factors of a number
func numPrimeFactors(n int) int {
	var res int
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			res++
			n /= i
		}
	}
	if n > 1 {
		res++
	}
	return res
}

// Function to calculate the sum of prime factors of a number
func sumPrimeFactors(n int) int {
	var res int
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			res += i
			n /= i
		}
	}
	if n > 1 {
		res += n
	}
	return res
}

// Function to check if a number is prime
func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

// Function to calculate the Euler's totient function of a number
func eulerTotient(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			res++
		}
	}
	return res
}

// Function to calculate the Möbius function of a number
func mobius(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				if n/i%2 == 0 {
					res -= 1
				} else {
					res += 1
				}
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the Möbius function
func sumDivisorsMobius(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				if n/i%2 == 0 {
					res -= mobius(n/i)
				} else {
					res += mobius(n/i)
				}
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the Euler's totient function
func sumDivisorsEuler(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += eulerTotient(n/i)
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization2(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += n / i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization3(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization4(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization5(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization6(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization7(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization8(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization9(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization10(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization11(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization12(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i + n/i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization13(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i
			}
		}
	}
	return res
}

// Function to calculate the sum of divisors of a number using the prime factorization
func sumDivisorsPrimeFactorization14(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		if gcd(i, n) == 1 {
			if n%i == 0 {
				res += i
			}
		}
	}
	return