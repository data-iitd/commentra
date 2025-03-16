package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// getScanner initializes a new scanner for reading from the provided file pointer.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords) // Split input by words
	scanner.Buffer(make([]byte, 500001), 500000) // Set buffer size for the scanner
	return scanner
}

// getNextString retrieves the next string from the scanner.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan() // Read the next token
	return scanner.Text() // Return the scanned text
}

// getNextInt retrieves the next integer from the scanner.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner)) // Convert the next string to an integer
	return i
}

// getNextInt64 retrieves the next int64 from the scanner.
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64) // Convert the next string to int64
	return i
}

// getNextUint64 retrieves the next uint64 from the scanner.
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64) // Convert the next string to uint64
	return i
}

// getNextFloat64 retrieves the next float64 from the scanner.
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64) // Convert the next string to float64
	return i
}

func main() {
	// Initialize file pointers for input and output
	fp := os.Stdin
	wfp := os.Stdout

	// Check for environment variables to override input and output file pointers
	if os.Getenv("MASPY") == "ますピ" {
		fp, _ = os.Open(os.Getenv("BEET_THE_HARMONY_OF_PERFECT")) // Open specified input file
	}
	if os.Getenv("MASPYPY") == "ますピッピ" {
		wfp, _ = os.Create(os.Getenv("NGTKANA_IS_GENIUS10")) // Create specified output file
	}

	// Create a scanner for reading input and a writer for output
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Read two strings from input
	s := getNextString(scanner)
	t := getNextString(scanner)

	// Calculate lengths of the input strings
	ns := len(s)
	nt := len(t)

	// Create a slice to hold repeated instances of string s
	ss := make([]string, (nt-1)/ns+1)
	for i := 0; i < len(ss); i++ {
		ss[i] = s // Fill the slice with string s
	}

	// Concatenate the repeated strings to form a new string
	sss := fmt.Sprintf("%s%s", strings.Join(ss, ""), strings.Join(ss, ""))

	// Initialize a boolean slice to track matches
	ok := make([]bool, ns)

	// Initialize a unique index array and a pattern matching structure
	uni := make([]int, ns)
	mp := MP{}
	mp.init(t) // Initialize the pattern matching table with string t
	m := 0
	for i := 0; i < ns; i++ {
		uni[i] = i // Set each index to itself initially
	}
	var o bool

	// Check for matches of string t in the concatenated string sss
	for i := 0; i < ns; i++ {
		o = true
		for m < nt {
			if t[m] != sss[i+m] { // Compare characters
				o = false
				break
			}
			m++
		}
		ok[i] = o // Store the result of the match
		if o {
			i += nt - mp.table[m] // Update index based on the pattern table
			m = mp.table[m] // Update match index
		}
		for m >= 0 && t[m] != sss[i+m] {
			i += m - mp.table[m] // Update index if mismatch occurs
			m = mp.table[m] // Update match index
		}
		i-- // Adjust index for the next iteration
		m++ // Move to the next character
	}

	// Calculate the answer based on the matches found
	ans := 0
	var r, rr int
	for i := 0; i < ns; i++ {
		if ok[i] == false {
			continue // Skip if no match
		}
		if ok[(i+nt)%ns] == false {
			continue // Skip if no match for the next index
		}
		r = root(i, uni) // Find the root of the current index
		rr = root((i+nt)%ns, uni) // Find the root of the next index
		if rr == r {
			fmt.Println(-1) // Output -1 if they are in the same component
			return
		}
		uni[rr] = r // Union the two components
	}

	// Count the number of matches for each unique root
	counter := make([]int, ns)
	for i := 0; i < ns; i++ {
		r = root(i, uni) // Find the root for the current index
		if ok[r] == false {
			continue // Skip if no match
		}
		counter[r]++ // Increment the count for the root
	}
	for i := 0; i < ns; i++ {
		if ans < counter[i] {
			ans = counter[i] // Update the answer with the maximum count
		}
	}

	// Output the final answer
	fmt.Println(ans)

	writer.Flush() // Flush the writer to ensure all output is written
}

// root function finds the root of the given index using path compression.
func root(i int, uni []int) int {
	if i == uni[i] {
		return i // Return if the index is its own root
	}

	uni[i] = root(uni[i], uni) // Path compression
	return uni[i] // Return the root
}

// MP struct holds the string and its pattern matching table.
type MP struct {
	s     string
	table []int
}

// init initializes the pattern matching table for the string.
func (mp *MP) init(s string) {
	mp.s = s
	n := len(s)
	table := make([]int, n+1)
	table[0] = -1 // Initialize the first value of the table
	j := -1
	for i := 0; i < n; i++ {
		for j >= 0 && s[i] != s[j] {
			j = table[j] // Update j based on the table
		}
		j++
		table[i+1] = j // Fill the table with the length of the longest prefix
	}
	mp.table = table // Assign the completed table to the MP struct
}
