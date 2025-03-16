
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	k, _ := fmt.Fscanf(reader, "%d\n", &k)

	t := 0
	for i := 1; i <= k; i++ {
		t = (t%k)*10 + 7
		if t%k == 0 {
			fmt.Println(i)
			break
		}
	}
	if i > k {
		fmt.Println(-1)
	}
}

