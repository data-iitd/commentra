package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read a line of integers
func I() []int {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	if s == "" {
		return []int{}
	}
	ss := strings.Split(s, " ")
	var ii []int
	for _, s := range ss {
		i, _ := strconv.Atoi(s)
		ii = append(ii, i)
	}
	return ii
}

// Read a single line of input
func IS() string {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	return s
}

// Read a single integer
func IN() int {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	i, _ := strconv.Atoi(s)
	return i
}

// Read a single float
func IF() float64 {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, " ", "", -1)
	s = strings.Replace(s, "\n", "", -1)
	f, _ := strconv.ParseFloat(s, 64)
	return f
}

func main() {
	// Read the number of elements
	n := IN()

	// Read the list of integers
	l := I()

	// Initialize a variable to track unique counts
	f := 1

	// Initialize a counter for unique elements
	c := 0

	// Iterate through the sorted list to count unique elements
	for i := 0; i < len(l); i++ {
		if l[i] > c {
			c++
		}
	}

	// Output the total count of unique elements
	fmt.Println(c + 1)
}

