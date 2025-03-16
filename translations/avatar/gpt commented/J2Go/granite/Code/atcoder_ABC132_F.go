
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define the modulo constant for calculations to prevent overflow
	const mod = 1e9 + 7

	// Initialize scanner to read input values
	sc := bufio.NewScanner(os.Stdin)

	// Read the values of n and k from input
	sc.Scan()
	n := int(readNum(sc.Bytes()))
	sc.Scan()
	k := int(readNum(sc.Bytes()))

	// Create a list to store the lengths of segments
	var len []int

	// Initialize the starting point for segment calculation
	l := 1

	// Calculate the lengths of segments based on the value of n
	for l <= n {
		// Calculate the right endpoint of the current segment
		r := n / (n / l)
		// Add the length of the current segment to the list
		len = append(len, r-l+1)
		// Move to the next segment
		l = r + 1
	}

	// Get the total number of segments calculated
	q := len(len)

	// Initialize a dynamic programming array to store results
	dp := make([]int64, k*(q+1))

	// Fill the dp array for the first segment
	for j := 1; j <= q; j++ {
		dp[j] = int64(len[j-1]) + dp[j-1]
	}

	// Fill the dp array for subsequent segments
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			// Calculate the number of ways to form segments
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1]+dp[(i-1)*(q+1)+q-j+1]*int64(len[j-1])
			// Apply modulo to keep the value within limits
			dp[i*(q+1)+j] %= mod
		}
	}

	// Output the final result, which is the number of ways to form k segments
	fmt.Println(dp[k*(q+1)-1])
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(scanner *bufio.Scanner) (a int) {
	scanner.Scan()
	readInt(scanner.Bytes(), 0, &a)
	return
}

func readTwoNums(scanner *bufio.Scanner) (a int, b int) {
	res := readNNums(scanner, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(scanner *bufio.Scanner, n int) []int {
	res := make([]int, n)
	x := 0
	scanner.Scan()
	for i := 0; i < n; i++ {
		for x < len(scanner.Bytes()) && scanner.Bytes()[x] =='' {
			x++
		}
		x = readInt(scanner.Bytes(), x, &res[i])
	}
	return res
}

func fillNNums(scanner *bufio.Scanner, n int, res []int) {
	x := 0
	scanner.Scan()
	for i := 0; i < n; i++ {
		for x < len(scanner.Bytes()) && scanner.Bytes()[x] =='' {
			x++
		}
		x = readInt(scanner.Bytes(), x, &res[i])
	}
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		res := solve(n, k)
		fmt.Println(res)
	}
}

func solve(n, k int) int {
	MOD := 1e9 + 7

	var seg []int

	for l := 1; l <= n; {
		r := n / (n / l)
		seg = append(seg, r-l+1)
		l = r + 1
	}

	q := len(seg)

	dp := make([]int64, k*(q+1))

	for j := 1; j <= q; j++ {
		dp[j] = int64(seg[j-1]) + dp[j-1]
	}

	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1]+dp[(i-1)*(q+1)+q-j+1]*int64(seg[j-1])
			dp[i*(q+1)+j] %= MOD
		}
	}

	return int(dp[k*(q+1)-1])
}