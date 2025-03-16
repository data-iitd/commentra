

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	// Read the number of elements N
	N := readInt()

	// Read the list of integers S, sort them in descending order
	S := readIntSlice()
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})

	// Initialize a flag array to keep track of used elements
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	// Initialize the current list with the first element of S
	cur := make([]int, 1)
	cur[0] = S[0]

	// Set the flag for the first element to False
	flag[0] = false

	// Loop through N times
	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)

		// Iterate over the elements of S
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				// Add the element to cur, set its flag to False, and increment j
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}

		// If no such element is found, return "No"
		if j == jM {
			fmt.Println("No")
			return
		}

		// Sort cur in descending order
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}

	// Return "Yes" if the condition is satisfied
	fmt.Println("Yes")
}

func readInt() int {
	i, _ := fmt.Fscanf(in, "%d", &i)
	return i
}

func readIntSlice() []int {
	n := readInt()
	s := make([]int, n)
	for i := range s {
		s[i] = readInt()
	}
	return s
}

func readString() string {
	s, _ := fmt.Fscanf(in, "%s", &s)
	return s
}

func readStringSlice() []string {
	n := readInt()
	s := make([]string, n)
	for i := range s {
		s[i] = readString()
	}
	return s
}

func readInt64() int64 {
	i, _ := fmt.Fscanf(in, "%d", &i)
	return i
}

func readInt64Slice() []int64 {
	n := readInt()
	s := make([]int64, n)
	for i := range s {
		s[i] = readInt64()
	}
	return s
}

func main() {
	// Read the number of elements N
	N := readInt()

	// Read the list of integers S, sort them in descending order
	S := readIntSlice()
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})

	// Initialize a flag array to keep track of used elements
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	// Initialize the current list with the first element of S
	cur := make([]int, 1)
	cur[0] = S[0]

	// Set the flag for the first element to False
	flag[0] = false

	// Loop through N times
	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)

		// Iterate over the elements of S
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				// Add the element to cur, set its flag to False, and increment j
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}

		// If no such element is found, return "No"
		if j == jM {
			fmt.Println("No")
			return
		}

		// Sort cur in descending order
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}

	// Return "Yes" if the condition is satisfied
	fmt.Println("Yes")
}

func readInt() int {
	i, _ := fmt.Fscanf(in, "%d", &i)
	return i
}

func readIntSlice() []int {
	n := readInt()
	s := make([]int, n)
	for i := range s {
		s[i] = readInt()
	}
	return s
}

func readString() string {
	s, _ := fmt.Fscanf(in, "%s", &s)
	return s
}

func readStringSlice() []string {
	n := readInt()
	s := make([]string, n)
	for i := range s {
		s[i] = readString()
	}
	return s
}

func readInt64() int64 {
	i, _ := fmt.Fscanf(in, "%d", &i)
	return i
}

func readInt64Slice() []int64 {
	n := readInt()
	s := make([]int64, n)
	for i := range s {
		s[i] = readInt64()
	}
	return s
}

