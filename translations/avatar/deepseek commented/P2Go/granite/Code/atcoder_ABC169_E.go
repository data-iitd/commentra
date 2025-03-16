
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func resolve() {
	// Read the number of pairs
	n := readInt()

	// Initialize lists to store the lower and higher values of each pair
	low := make([]int, n)
	high := make([]int, n)

	// Loop to read each pair and append values to the lists
	for i := 0; i < n; i++ {
		a, b := readTwoInt()
		low[i] = a
		high[i] = b
	}

	// Sort the lists
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of pairs is odd or even
	if n%2 == 1 {
		// If odd, calculate the range between the middle elements
		fmt.Println(high[n/2]-low[n/2]+1)
	} else {
		// If even, calculate the average of the middle elements and print the range
		hh := (high[n/2-1] + high[n/2]) / 2
		ll := (low[n/2-1] + low[n/2]) / 2
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
	var n1, n2 int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n1)
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n2)
	return n1, n2
}

func main() {
	resolve()
}

