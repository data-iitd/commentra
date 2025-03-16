
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Fast I/O setup
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Declare variables to store input values
	var A, B, C, K int64
	fmt.Fscanf(reader, "%d %d %d %d\n", &A, &B, &C, &K)

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// Output the minimum of A and K
		fmt.Fprintf(writer, "%d\n", min(A, K))
	} else {
		// Calculate the result by subtracting the excess amount from A
		fmt.Fprintf(writer, "%d\n", A-(K-(A+B)))
	}
}

// Function to check and update the minimum value of a variable
func min(a, b int64) int64 {
	if a > b {
		return b
	}
	return a
}

// Define constants for maximum values
const (
	INF  = (1 << 30) - 1
	INF64 = (1 << 60) - 1
	MOD  = 1000000007
)

// Macro to iterate over all elements in a container
func range(a, b int) []int {
	res := make([]int, b-a)
	for i := range res {
		res[i] = a + i
	}
	return res
}

// Macro to iterate over all elements in a container
func rrange(a, b int) []int {
	res := make([]int, b-a)
	for i := range res {
		res[i] = b - 1 - i
	}
	return res
}

// Macro to iterate over all elements in a container
func all(a []int) []int {
	return range(0, len(a))
}

// Macro to iterate over all elements in a container
func rall(a []int) []int {
	return rrange(0, len(a))
}

// Macro to iterate over all elements in a container
func par(a...int) []int {
	return a
}

// Macro to iterate over all elements in a container
func rpar(a...int) []int {
	res := make([]int, len(a))
	for i := range a {
		res[i] = a[len(a)-1-i]
	}
	return res
}

// Macro to iterate over all elements in a container
func rep(n int) []int {
	return range(0, n)
}

// Macro to iterate over all elements in a container
func rrep(n int) []int {
	return rrange(0, n)
}

// Macro to iterate over all elements in a container
func tab(n int) []int {
	return rep(n)
}

// Macro to iterate over all elements in a container
func rtab(n int) []int {
	return rrep(n)
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

// Function to calculate the factorial of a number
func factorial(n int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

// Function to calculate the combination of two numbers
func combination(n, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
}

// Function to calculate the permutation of two numbers
func permutation(n, r int) int {
	return factorial(n) / factorial(n-r)
}

// Function to calculate the power of a number
func power(x, n int) int {
	res := 1
	for i := 0; i < n; i++ {
		res *= x
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

// Function to calculate the sum of all elements in a slice
func sum(a []int) int {
	res := 0
	for _, v := range a {
		res += v
	}
	return res
}

// Function to calculate the product of all elements in a slice
func product(a []int) int {
	res := 1
	for _, v := range a {
		res *= v
	}
	return res
}

// Function to calculate the minimum value of a slice
func min(a []int) int {
	res := a[0]
	for _, v := range a {
		if v < res {
			res = v
		}
	}
	return res
}

// Function to calculate the maximum value of a slice
func max(a []int) int {
	res := a[0]
	for _, v := range a {
		if v > res {
			res = v
		}
	}
	return res
}

// Function to calculate the median value of a slice
func median(a []int) float64 {
	sort.Ints(a)
	n := len(a)
	if n%2 == 0 {
		return float64(a[n/2-1]+a[n/2]) / 2
	} else {
		return float64(a[n/2])
	}
}

// Function to calculate the mode value of a slice
func mode(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}
	maxCount := 0
	mode := 0
	for k, v := range m {
		if v > maxCount {
			maxCount = v
			mode = k
		}
	}
	return mode
}

// Function to calculate the mean value of a slice
func mean(a []int) float64 {
	return float64(sum(a)) / float64(len(a))
}

// Function to calculate the standard deviation of a slice
func stddev(a []int) float64 {
	mean := mean(a)
	var sum float64
	for _, v := range a {
		sum += math.Pow(float64(v)-mean, 2)
	}
	return math.Sqrt(sum / float64(len(a)))
}

// Function to calculate the variance of a slice
func variance(a []int) float64 {
	mean := mean(a)
	var sum float64
	for _, v := range a {
		sum += math.Pow(float64(v)-mean, 2)
	}
	return sum / float64(len(a))
}

// Function to calculate the range of a slice
func range(a []int) int {
	return max(a) - min(a)
}

// Function to calculate the midrange of a slice
func midrange(a []int) float64 {
	return float64(min(a)+max(a)) / 2
}

// Function to calculate the quartiles of a slice
func quartiles(a []int) []float64 {
	sort.Ints(a)
	n := len(a)
	if n%2 == 0 {
		return []float64{float64(a[n/2-1]), float64(a[n/2]), float64(a[n/2+1])}
	} else {
		return []float64{float64(a[n/2]), float64(a[n/2+1])}
	}
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the median absolute deviation of a slice
func mad(a []int) float64 {
	median := median(a)
	var sum float64
	for _, v := range a {
		sum += math.Abs(float64(v) - median)
	}
	return sum / float64(len(a))
}

// Function to calculate the skewness of a slice
func skewness(a []int) float64 {
	mean := mean(a)
	var sum float64
	for _, v := range a {
		sum += math.Pow(float64(v)-mean, 3)
	}
	return sum / math.Pow(stddev(a), 3)
}

// Function to calculate the kurtosis of a slice
func kurtosis(a []int) float64 {
	mean := mean(a)
	var sum float64
	for _, v := range a {
		sum += math.Pow(float64(v)-mean, 4)
	}
	return sum / math.Pow(stddev(a), 4) - 3
}

// Function to calculate the percentile of a slice
func percentile(a []int, p float64) float64 {
	sort.Ints(a)
	n := len(a)
	if p < 0 || p > 100 {
		return -1
	}
	rank := (p / 100) * float64(n)
	floorRank := int(rank)
	decimalRank := rank - float64(floorRank)
	if floorRank == n {
		return float64(a[n-1])
	} else {
		return a[floorRank-1] + decimalRank*(a[floorRank]-a[floorRank-1])
	}
}

// Function to calculate the quartile deviation of a slice
func quartileDev(a []int) float64 {
	quartiles := quartiles(a)
	return (quartiles[2] - quartiles[0]) / 2
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percentile rank of a value in a slice
func percentileRank(a []int, x int) float64 {
	return (percentile(a, 100) - float64(x)) / (percentile(a, 100) - percentile(a, 0))
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percentile rank of a value in a slice
func percentileRank(a []int, x int) float64 {
	return (percentile(a, 100) - float64(x)) / (percentile(a, 100) - percentile(a, 0))
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percentile rank of a value in a slice
func percentileRank(a []int, x int) float64 {
	return (percentile(a, 100) - float64(x)) / (percentile(a, 100) - percentile(a, 0))
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percentile rank of a value in a slice
func percentileRank(a []int, x int) float64 {
	return (percentile(a, 100) - float64(x)) / (percentile(a, 100) - percentile(a, 0))
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percentile rank of a value in a slice
func percentileRank(a []int, x int) float64 {
	return (percentile(a, 100) - float64(x)) / (percentile(a, 100) - percentile(a, 0))
}

// Function to calculate the interquartile range of a slice
func iqr(a []int) float64 {
	quartiles := quartiles(a)
	return quartiles[2] - quartiles[0]
}

// Function to calculate the coefficient of variation of a slice
func coeffVar(a []int) float64 {
	return stddev(a) / mean(a)
}

// Function to calculate the z-score of a value in a slice
func zScore(a []int, x int) float64 {
	return (float64(x) - mean(a)) / stddev(a)
}

// Function to calculate the percen