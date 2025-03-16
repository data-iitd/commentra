
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of strings to process
	N := readInt()

	// Read N strings from input
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = readString()
	}

	// Define the target characters to count
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each target character
	march_lis := make([]int, len(march))

	// Count the occurrences of each character in the input strings
	for _, s := range S {
		if s[0] == strings.ToUpper(march[0]) {
			march_lis[0]++
		}
		if s[0] == strings.ToUpper(march[1]) {
			march_lis[1]++
		}
		if s[0] == strings.ToUpper(march[2]) {
			march_lis[2]++
		}
		if s[0] == strings.ToUpper(march[3]) {
			march_lis[3]++
		}
		if s[0] == strings.ToUpper(march[4]) {
			march_lis[4]++
		}
	}

	// Initialize the answer variable to store the result
	ans := 0

	// Calculate the number of ways to choose 3 different characters from the counts
	for x, y, z := range combinations(march_lis, 3) {
		ans += x * y * z
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to read a line of input and strip whitespace
func readString() string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

// Function to read an integer from input
func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

// Function to read a map of integers from input
func readMap() map[string]int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	m := make(map[string]int)
	for i := 0; i < len(s); i += 2 {
		m[s[i:i+2]] = int(s[i+1])
	}
	return m
}

// Function to read a list of integers from input
func readList() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read multiple lists of integers and zip them together
func readZip(n int) [][]int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([][]int, n)
	for i := 0; i < n; i++ {
		l[i] = make([]int, len(s)/n)
		for j := 0; j < len(s)/n; j++ {
			l[i][j], _ = strconv.Atoi(string(s[i*len(s)/n+j]))
		}
	}
	return l
}

// Function to read multiple lists of integers and zip them together
func readZipString(n int) [][]string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([][]string, n)
	for i := 0; i < n; i++ {
		l[i] = make([]string, len(s)/n)
		for j := 0; j < len(s)/n; j++ {
			l[i][j] = string(s[i*len(s)/n+j])
		}
	}
	return l
}

// Function to read a list of integers from input
func readListInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListFloatString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListIntString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListStringInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListStringFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListStringString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListIntFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListIntStringInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListIntStringFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListIntStringString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListFloatStringInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListFloatStringFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListFloatStringString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListStringIntInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListStringIntFloat() []float64 {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]float64, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.ParseFloat(string(s[i]), 64)
	}
	return l
}

// Function to read a list of integers from input
func readListStringIntString() []string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		l[i] = string(s[i])
	}
	return l
}

// Function to read a list of integers from input
func readListStringFloatInt() []int {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	l := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		l[i], _ = strconv.Atoi(string(s[i]))
	}
	return l
}

// Function to read a list of integers from input
func readListStringFloatFloat() []float64 {
	in := bufio.NewRead