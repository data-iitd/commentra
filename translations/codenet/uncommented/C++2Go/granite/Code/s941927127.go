
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	W := scanner.Text()

	sort.Strings(W)

	for i := 0; i < len(W); i += 2 {
		if W[i]!= W[i+1] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

