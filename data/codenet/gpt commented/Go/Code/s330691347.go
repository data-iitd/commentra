package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// out is a utility function for printing output, currently commented out.
func out(x ...interface{}) {
	//	fmt.Println(x...)
}

// sc is a scanner for reading input from standard input.
var sc = bufio.NewScanner(os.Stdin)

// nextInt reads the next integer from input and returns it.
func nextInt() int {
	sc.Scan() // Scan the next token from input
	i, e := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return i // Return the integer value
}

// nextString reads the next string from input and returns it.
func nextString() string {
	sc.Scan() // Scan the next token from input
	return sc.Text() // Return the scanned text
}

// Data represents a single data entry with a string field.
type Data struct {
	X string
}

// Datas is a slice of Data, implementing sort.Interface.
type Datas []Data

// Len returns the number of elements in the slice.
func (p Datas) Len() int {
	return len(p)
}

// Swap exchanges the elements with indexes i and j.
func (p Datas) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Less reports whether the element with index i should sort before the element with index j.
func (p Datas) Less(i, j int) bool {
	return p[i].X < p[j].X // Sort based on the string field X
}

func main() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input by words
	N := nextInt() // Read the number of data entries
	L := nextInt() // Read an additional integer (not used further in the code)
	s := make(Datas, N) // Create a slice of Datas with length N

	// Read N strings into the slice s
	for i := 0; i < N; i++ {
		s[i].X = nextString() // Populate each Data entry with a string
	}

	out(N, L, s) // Output the initial values (commented out)
	sort.Sort(s) // Sort the slice of Data entries
	out(s) // Output the sorted slice (commented out)

	// Concatenate all strings in the sorted slice into a single result
	ans := ""
	for i := 0; i < N; i++ {
		ans = ans + s[i].X // Append each string to ans
	}
	fmt.Println(ans) // Print the concatenated result
}
