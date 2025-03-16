
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

// Scanner to read input in a word-by-word manner
#define sc (bufio.NewScanner(os.Stdin))

// Converts a scanned string to an integer
func scanInt() int {
	num, _ := strconv.Atoi(scanString())
	return num
}

// Reads a single word from the input
func scanString() string {
	sc.Scan()
	return sc.Text()
}

// Reads a slice of integers from input
func scanInts(n int) []int {
	sl := make([]int, n)
	for i := range sl {
		sl[i] = scanInt()
	}
	return sl
}

// Reads a slice of strings from input
func scanStrings(n int) []string {
	sl := make([]string, n)
	for i := range sl {
		sl[i] = scanString()
	}
	return sl
}

// Initializes the scanner to split input words
func init() {
	sc.Split(bufio.ScanWords)
}

// Main function to execute the program
func main() {
	// Read initial values for r, D, and x
	r, D, x := scanInt(), scanInt(), scanInt()
	
	// Loop to calculate and print the values of x for 10 iterations
	for i := 1; i <= 10; i++ {
		x = r*x - D
		fmt.Println(x)
	}
}

// END-OF-CODE