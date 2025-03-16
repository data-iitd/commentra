
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Step 1: Reading inputs
	X, Y, Z, K := readInt()

	// Step 2: Vector initialization and input
	A := readIntSlice(X)
	B := readIntSlice(Y)
	C := readIntSlice(Z)

	// Step 3: Sorting
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})
	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	// Step 4: Combining A and B
	AB := make([]int, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Step 5: Sorting AB
	sort.Slice(AB, func(i, j int) bool {
		return AB[i] > AB[j]
	})

	// Step 6: Combining AB and C
	ABC := make([]int, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Step 7: Sorting ABC
	sort.Slice(ABC, func(i, j int) bool {
		return ABC[i] > ABC[j]
	})

	// Step 8: Output
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i])
	}
}

func readInt() (int, int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var buf [1024]byte
	scanner.Buffer(buf[:], int(1e6+1))
	scanner.Split(bufio.ScanWords)
	var X, Y, Z, K int
	scanner.Scan()
	X, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	Y, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	Z, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	K, _ = strconv.Atoi(scanner.Text())
	return X, Y, Z, K
}

func readIntSlice(n int) []int {
	s := make([]int, n)
	scanner := bufio.NewScanner(os.Stdin)
	var buf [1024]byte
	scanner.Buffer(buf[:], int(1e6+1))
	scanner.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s[i], _ = strconv.Atoi(scanner.Text())
	}
	return s
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

