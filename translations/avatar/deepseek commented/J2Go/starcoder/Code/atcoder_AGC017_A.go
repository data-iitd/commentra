
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate combination (n choose m) using BigInteger for large numbers
func C(n, m int64) *big.Int {
	res := big.NewInt(1) // Initialize result to 1
	// Calculate product from m-n+1 to m
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(i))
	}
	// Divide by product from 1 to n
	for i := int64(1); i <= n; i++ {
		res.Div(res, big.NewInt(i))
	}
	return res
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	sc.Scan()
	p, _ := strconv.ParseInt(sc.Text(), 10, 64)
	k0 := int64(0) // Count of even numbers
	k1 := int64(0) // Count of odd numbers
	for i := int64(0); i < n; i++ {
		sc.Scan()
		x, _ := strconv.ParseInt(sc.Text(), 10, 64)
		if x%2 == 1 {
			k1++
		} else {
			k0++
		}
	}
	ans := big.NewInt(1) // Initialize result for number of ways to arrange items
	for i := int64(0); i < k0; i++ {
		ans.Mul(ans, big.NewInt(2)) // Multiply by 2 for each even number
	}
	if p == 0 {
		add := big.NewInt(0)
		// Sum combinations of odd numbers, taking 0, 2, 4,... odd numbers
		for i := int64(0); i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add) // Multiply result by the sum
		fmt.Println(ans)  // Print final result
	} else {
		add := big.NewInt(0)
		// Sum combinations of odd numbers, taking 1, 3, 5,... odd numbers
		for i := int64(1); i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add) // Multiply result by the sum
		fmt.Println(ans)  // Print final result
	}
}

