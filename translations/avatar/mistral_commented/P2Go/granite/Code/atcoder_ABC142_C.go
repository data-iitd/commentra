
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
	// Define the number of elements in the list 'A'
	N := nextInt()

	// Initialize an empty list 'A' with 'N' elements
	// Each element is a tuple containing an index and a value
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, nextInt()}
	}

	// Sort the list 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the list 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A__[i])
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func nextStringArray(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
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

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func allSame(a []int) bool {
	for i := 1; i < len(a); i++ {
		if a[i]!= a[0] {
			return false
		}
	}
	return true
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i]!= s[len(s)-1-i] {
			return false
		}
	}
	return true
}

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

func nextPermutation(a []int) bool {
	i := len(a) - 1
	for i > 0 && a[i-1] >= a[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(a) - 1
	for j >= 0 && a[j] <= a[i-1] {
		j--
	}
	a[i-1], a[j] = a[j], a[i-1]
	a[i:] = reverse(a[i:])
	return true
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	// Define the number of elements in the list 'A'
	N := nextInt()

	// Initialize an empty list 'A' with 'N' elements
	// Each element is a tuple containing an index and a value
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, nextInt()}
	}

	// Sort the list 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the list 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A__[i])
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func nextStringArray(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
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

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func allSame(a []int) bool {
	for i := 1; i < len(a); i++ {
		if a[i]!= a[0] {
			return false
		}
	}
	return true
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i]!= s[len(s)-1-i] {
			return false
		}
	}
	return true
}

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

func nextPermutation(a []int) bool {
	i := len(a) - 1
	for i > 0 && a[i-1] >= a[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(a) - 1
	for j >= 0 && a[j] <= a[i-1] {
		j--
	}
	a[i-1], a[j] = a[j], a[i-1]
	a[i:] = reverse(a[i:])
	return true
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	// Define the number of elements in the list 'A'
	N := nextInt()

	// Initialize an empty list 'A' with 'N' elements
	// Each element is a tuple containing an index and a value
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, nextInt()}
	}

	// Sort the list 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the list 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A__[i])
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func nextStringArray(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
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

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func allSame(a []int) bool {
	for i := 1; i < len(a); i++ {
		if a[i]!= a[0] {
			return false
		}
	}
	return true
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i]!= s[len(s)-1-i] {
			return false
		}
	}
	return true
}

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

func nextPermutation(a []int) bool {
	i := len(a) - 1
	for i > 0 && a[i-1] >= a[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(a) - 1
	for j >= 0 && a[j] <= a[i-1] {
		j--
	}
	a[i-1], a[j] = a[j], a[i-1]
	a[i:] = reverse(a[i:])
	return true
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	// Define the number of elements in the list 'A'
	N := nextInt()

	// Initialize an empty list 'A' with 'N' elements
	// Each element is a tuple containing an index and a value
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, nextInt()}
	}

	// Sort the list 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the list 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A__[i])
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func nextStringArray(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
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

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func allSame(a []int) bool {
	for i := 1; i < len(a); i++ {
		if a[i]!= a[0] {
			return false
		}
	}
	return true
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i]!= s[len(s)-1-i] {
			return false
		}
	}
	return true
}

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

func nextPermutation(a []int) bool {
	i := len(a) - 1
	for i > 0 && a[i-1] >= a[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(a) - 1
	for j >= 0 && a[j] <= a[i-1] {
		j--
	}
	a[i-1], a[j] = a[j], a[i-1]
	a[i:] = reverse(a[i:])
	return true
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func main() {
	// Define the number of elements in the list 'A'
	N := nextInt()

	// Initialize an empty list 'A' with 'N' elements
	// Each element is a tuple containing an index and a value
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, nextInt()}
	}

	// Sort the list 'A' based on the second element of each tuple (the value)
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Iterate through the list 'A__' (excluding the last element) and print each index
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A__[i])
	}

	// Print the last index in 'A__'
	fmt.Println(A__[N-1])
}

func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func nextStringArray(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
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

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

fun