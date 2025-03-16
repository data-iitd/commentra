// Package main is the entry point of the program
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// getScanner returns a new bufio.Scanner from the given file pointer
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // Buffer size for efficient reading
	return scanner
}

// getNextString reads and returns the next string from the scanner
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt reads and converts the next integer from the scanner
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// getNextInt64 reads and converts the next int64 from the scanner
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// getNextUint64 reads and converts the next uint64 from the scanner
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// getNextFloat64 reads and converts the next float64 from the scanner
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

// main function is the entry point of the program
func main() {
	// Open the standard input and output files
	fp := os.Stdin
	wfp := os.Stdout

	// If environment variables are set, open input and output files accordingly
	if os.Getenv("MASPY") == "ますピ" {
		fp, _ = os.Open(os.Getenv("BEET_THE_HARMONY_OF_PERFECT"))
	}
	if os.Getenv("MASPYPY") == "ますピッピ" {
		wfp, _ = os.Create(os.Getenv("NGTKANA_IS_GENIUS10"))
	}

	// Initialize scanner and writer
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Read the first two strings from the input
	s := getNextString(scanner)
	t := getNextString(scanner)

	// Initialize variables and structures
	ns := len(s)
	nt := len(t)
	ss := make([]string, (nt-1)/ns+1)

	// Initialize ss with repeated string s
	for i := 0; i < len(ss); i++ {
		ss[i] = s
	}

	// Combine all ss strings into one long string
	sss := fmt.Sprintf("%s%s", strings.Join(ss, ""), strings.Join(ss, ""))

	// Initialize boolean array ok to keep track of unique characters
	ok := make([]bool, ns)

	// Initialize unordered map mp and array uni for suffix array calculation
	mp := MP{}
	mp.init(t)
	m := 0

	// Initialize uni array with indices from 0 to n-1
	uni := make([]int, ns)
	for i := 0; i < ns; i++ {
		uni[i] = i
	}

	// Initialize variable o for checking if current and next characters match
	var o bool

	// Iterate through all characters in string s
	for i := 0; i < ns; i++ {
		// Initialize o to true
		o = true

		// Iterate through all characters in string t
		for m < nt {
			// Check if current character in s matches the character at the same position in t
			if t[m] != sss[i+m] {
				// If not, set o to false and break the loop
				o = false
				break
			}
			// Increment m
			m++
		}

		// If all characters match, set ok[i] to true and update variables r and m accordingly
		if o {
			i += nt - mp.table[m]
			m = mp.table[m]
		}

		// While characters in s and t do not match, update i and m accordingly
		for m >= 0 && t[m] != sss[i+m] {
			i += m - mp.table[m]
			m = mp.table[m]
		}

		// Decrement i and increment m to move to the next pair of characters
		i--
		m++
	}

	// Initialize variable ans to store the answer
	ans := 0

	// Initialize variables r and rr for root calculation
	var r, rr int

	// Iterate through all characters in string s again
	for i := 0; i < ns; i++ {
		// If ok[i] is false, continue to the next iteration
		if ok[i] == false {
			continue
		}

		// If ok[(i+nt)%ns] is false, continue to the next iteration
		if ok[(i+nt)%ns] == false {
			continue
		}

		// Calculate roots r and rr of indices i and (i+nt)%ns respectively
		r = root(i, uni)
		rr = root((i+nt)%ns, uni)

		// If roots r and rr are equal, print -1 and exit the program
		if rr == r {
			fmt.Println(-1)
			return
		}

		// Update uni array with root r
		uni[rr] = r
	}

	// Initialize counter array to store the frequency of each root
	counter := make([]int, ns)

	// Iterate through all roots and update their frequencies in counter array
	for i := 0; i < ns; i++ {
		r = root(i, uni)
		if ok[r] == false {
			continue
		}
		counter[r]++
	}

	// Find the maximum frequency in counter array and store it in variable ans
	for i := 0; i < ns; i++ {
		if ans < counter[i] {
			ans = counter[i]
		}
	}

	// Print the answer
	fmt.Println(ans)

	// Flush the writer buffer
	writer.Flush()
}

// root function returns the root of the given index in uni array
func root(i int, uni []int) int {
	// If index i is equal to its root, return i
	if i == uni[i] {
		return i
	}

	// Recursively call root function with the root of index i
	uni[i] = root(uni[i], uni)
	return uni[i]
}

// MP type represents a suffix array data structure
type MP struct {
	s     string // Input string
	table []int  // Suffix array
}

// init initializes the MP structure with the given string s
func (mp *MP) init(s string) {
	mp.s = s
	n := len(s)
	table := make([]int, n+1)
	table[0] = -1 // Set first index to -1 for initialization
	j := -1
	for i := 0; i < n; i++ {
		// While j is not equal to the root of the previous character, update j
		for j >= 0 && s[i] != s[j] {
			j = table[j]
		}
		j++
		// Set table[i] to the index of the next occurrence of the current character in s
		table[i+1] = j
	}
	mp.table = table
}
