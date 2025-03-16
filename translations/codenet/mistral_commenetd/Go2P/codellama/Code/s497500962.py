
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Main function is the entry point of the program
func main() {
	// Initialize variables R, G, B, and N with next integers
	R := nextInt()
	G := nextInt()
	B := nextInt()
	N := nextInt()

	// Initialize variable ans with zero
	var ans int

	// Nested for loops to iterate through all possible combinations of x and y within the range of N
	for x := 0; x <= N; x++ {
		for y := 0; y <= N; y++ {
			// Calculate temporary variable tmp
			tmp := N - R*x - G*y

			// Check if tmp is non-negative and the remainder of tmp when divided by B is zero
			if tmp >= 0 && tmp%B == 0:
				// Increment the value of ans if the condition is true
				ans += 1
		}
	}

	// Print the value of ans
	print(ans)
}

// Input related functions
var sc = bufio.NewScanner(os.Stdin)

func init() {
	// Initialize scanner buffer and split function
	sc.Buffer([]byte{}, math.MaxInt64)
	sc.Split(bufio.ScanWords)
}

func nextInt() int {
	// Read next word as string, convert it to integer, and return
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}

	return i
}

func nextFloat() float64 {
	// Read next word as string, convert it to float64, and return
	sc.Scan()
	f64, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}

	return f64
}

func nextString() string {
	// Read next word as string and return
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}

	return sc.Text()
}

// Utility functions
def abs(x):
	# Return absolute value of x
	return int(math.fabs(x))

def min(x, y):
	# Return minimum value of x and y
	return int(min(x, y))

def max(x, y):
	# Return maximum value of x and y
	return int(max(x, y))

# 