
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func resolve() {
	const MOD = 100000007

	// Read the number of intervals
	n := readInt()

	// Initialize lists to store the lower and upper bounds of the intervals
	low := make([]int, n)
	high := make([]int, n)

	// Read each interval and store the lower and upper bounds
	for i := 0; i < n; i++ {
		a, b := readTwoInt()
		low[i] = a  // Append the lower bound to the low list
		high[i] = b // Append the upper bound to the high list
	}

	// Sort the lower and upper bounds
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of intervals is odd
	if n%2 == 1 {
		// For odd number of intervals, calculate the range of the median interval
		fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
	} else {
		// For even number of intervals, calculate the average of the two middle values
		hh := (high[n/2-1] + high[n/2]) / 2  // Average of the two middle high values
		ll := (low[n/2-1] + low[n/2]) / 2    // Average of the two middle low values
		// Calculate the range and print the result
		fmt.Println(int((float64(hh)-float64(ll))*2) + 1)
	}
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readTwoInt() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n0, n1 int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d %d", &n0, &n1)
	return n0, n1
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func main() {
	resolve()
}

