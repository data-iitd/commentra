<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Include necessary headers: These headers are essential for input/output operations, using maps, sets, and vectors respectively.

// Define a macro for loop: This simplifies the for loop syntax, making the code more readable.

// Namespace usage: The code uses the std namespace to avoid prefixing standard library components with'std::'.

func solve(N int, T []int, M int, P []int, X []int) {
	// Solve function: This function processes the input data to calculate and output the results for each operation.
	for i := 0; i < M; i++ {
		// Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
		ans := 0
		for j := 0; j < N; j++ {
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	// Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
	reader := bufio.NewReader(os.Stdin)
	defer reader.Close()
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	T := make([]int, N)
	for i := 0; i < N; i++ {
		T[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}
	M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	P := make([]int, M)
	X := make([]int, M)
	for i := 0; i < M; i++ {
		P[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		X[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}
	solve(N, T, M, P, X)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

