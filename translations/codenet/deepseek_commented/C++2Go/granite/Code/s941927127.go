

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var W string
	fmt.Fscan(reader, &W)

	sort.Strings(W)

	for i := 0; i < len(W); i += 2 {
		if W[i]!= W[i+1] {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}

