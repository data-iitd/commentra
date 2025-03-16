// Import required libraries
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define constant value
const MOD = 1000000007

// Read input number of elements N
func main() {
	var N int
	fmt.Scan(&N)

	// Define a constant value for the size of the 2D array A
	const M = 1000000

	// Initialize NumPy array A with given size and input data
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Define a constant value for the size of the 2D array fact
	const Nsq = 1000

	// Initialize 2D NumPy array fact with given size and initial value 1
	fact := make([][]int, Nsq)
	for i := 0; i < Nsq; i++ {
		fact[i] = make([]int, Nsq)
		fact[i][0] = 1
	}

	// Calculate factorial for each cell in the 2D array fact using a loop
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[i][n] *= fact[i][n - 1]
			fact[i][n] %= MOD
		}
	}

	// Transpose the 2D array fact and calculate factorial for each cell in the new rows
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n][i] *= fact[n - 1][Nsq - 1]
			fact[n][i] %= MOD
		}
	}

	// Flatten the 2D array fact into a 1D NumPy array
	fact = flatten(fact)

	// Initialize NumPy array j with given size
	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}

	// Calculate the inverse of each element in the array inv using a list comprehension
	inv := make([]int, N)
	for i := 0; i < N; i++ {
		inv[i] = pow(i + 1, MOD - 2, MOD)
	}

	// Calculate cumulative sum of the array inv
	inv = cumsum(inv)

	// Calculate temporary array temp using elements from j and inv
	temp := make([]int, N)
	for i := 0; i < N; i++ {
		temp[i] = inv[j[i]] + inv[N - 1 - j[i]] - 1
	}

	// Calculate the answer ans using given formula
	ans := 0
	for i := 0; i < N; i++ {
		ans += A[i] * temp[i]
		ans %= MOD
	}

	// Modulo the answer ans with given constant value MOD
	ans %= MOD

	// Multiply the answer ans with the last element of fact array
	ans *= fact[N]
	ans %= MOD

	// Print the answer ans
	fmt.Println(ans)
}

// Flatten the 2D array fact into a 1D NumPy array
func flatten(fact [][]int) []int {
	var Nsq = len(fact)
	var N = Nsq * Nsq
	var flat = make([]int, N)
	for i := 0; i < Nsq; i++ {
		for j := 0; j < Nsq; j++ {
			flat[i * Nsq + j] = fact[i][j]
		}
	}
	return flat
}

// Calculate cumulative sum of the array inv
func cumsum(inv []int) []int {
	var N = len(inv)
	var cum = make([]int, N)
	cum[0] = inv[0]
	for i := 1; i < N; i++ {
		cum[i] = cum[i - 1] + inv[i]
	}
	return cum
}

// Calculate the inverse of a number using the extended Euclidean algorithm
func inv(a int) int {
	var t, newt, r, newr = 0, 1, 1, 0
	for newr!= 0 {
		q := r / newr
		t, newt = newt, t - q * newt
		r, newr = newr, r - q * newr
	}
	if r > 1 {
		return 0
	}
	if t < 0 {
		t += MOD
	}
	return t
}

// Calculate the power of a number using the binary exponentiation algorithm
func pow(a, b, m int) int {
	var ans = 1
	for b > 0 {
		if b & 1 == 1 {
			ans *= a
			ans %= m
		}
		a *= a
		a %= m
		b >>= 1
	}
	return ans
}

// Print the answer ans
func print(ans int) {
	fmt.Println(ans)
}

// Read input number of elements N
func read(reader *bufio.Reader) (N int) {
	fmt.Fscan(reader, &N)
	return
}

// Read input data
func readArray(reader *bufio.Reader, N int) []int {
	var A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	return A
}

// Read input data
func readInt(reader *bufio.Reader) (a int) {
	fmt.Fscan(reader, &a)
	return
}

// Read input data
func readInts(reader *bufio.Reader, N int) []int {
	var A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	return A
}

// Read input data
func readString(reader *bufio.Reader) (a string) {
	fmt.Fscan(reader, &a)
	return
}

// Read input data
func readStrings(reader *bufio.Reader, N int) []string {
	var A = make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	return A
}

// Convert a number to a string
func toString(a int) string {
	return strconv.Itoa(a)
}

// Print the answer ans
func write(writer *bufio.Writer, ans int) {
	fmt.Fprintln(writer, ans)
}

// Print the answer ans
func writeArray(writer *bufio.Writer, A []int) {
	for i := 0; i < len(A); i++ {
		fmt.Fprint(writer, A[i], " ")
	}
	fmt.Fprintln(writer)
}

// Print the answer ans
func writeString(writer *bufio.Writer, a string) {
	fmt.Fprintln(writer, a)
}

// Print the answer ans
func writeStrings(writer *bufio.Writer, A []string) {
	for i := 0; i < len(A); i++ {
		fmt.Fprintln(writer, A[i])
	}
}

// END-OF-CODE
