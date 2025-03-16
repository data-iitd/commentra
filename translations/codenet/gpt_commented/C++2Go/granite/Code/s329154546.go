
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of strings (N) and the length of each string (L)
	N, L := readInt(), readInt()

	// Declare an array to hold the strings
	S := make([]string, N)

	// Input the strings from the user
	for i := 0; i < N; i++ {
		S[i] = readString()
	}

	// Sort the array of strings in lexicographical order
	sort.Strings(S)

	// Output the sorted strings
	for _, s := range S {
		fmt.Print(s)
	}

	// Print a newline at the end of the output
	fmt.Println()
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := power(x, n/2)
	tmp *= tmp
	if n%2 == 1 {
		tmp *= x
	}
	return tmp
}

func abs(x int) int {
	return max(x, -x)
}

func allSame(a []int) bool {
	pr := a[0]
	for _, p := range a {
		if pr!= p {
			return false
		}
	}
	return true
}

func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

func main() {
	// Read the number of strings (N) and the length of each string (L)
	N, L := readInt(), readInt()

	// Declare an array to hold the strings
	S := make([]string, N)

	// Input the strings from the user
	for i := 0; i < N; i++ {
		S[i] = readString()
	}

	// Sort the array of strings in lexicographical order
	sort.Strings(S)

	// Output the sorted strings
	for _, s := range S {
		fmt.Print(s)
	}

	// Print a newline at the end of the output
	fmt.Println()
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := power(x, n/2)
	tmp *= tmp
	if n%2 == 1 {
		tmp *= x
	}
	return tmp
}

func abs(x int) int {
	return max(x, -x)
}

func allSame(a []int) bool {
	pr := a[0]
	for _, p := range a {
		if pr!= p {
			return false
		}
	}
	return true
}

func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

