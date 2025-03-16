
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 3: Read input strings
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	n := len(a) - 1
	b, _ := reader.ReadString('\n')
	m := len(b) - 1

	// Step 4: Calculate the minimum number of differences
	ans := n + 10
	for i := 0; i <= n-m; i++ {
		sum := 0
		for j := 0; j < m; j++ {
			if a[i+j]!= b[j] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}

	// Step 5: Output the result
	fmt.Println(ans)
}

