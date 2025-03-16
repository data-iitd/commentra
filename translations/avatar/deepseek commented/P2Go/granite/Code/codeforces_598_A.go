

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	t, _ := fmt.Fscanf(reader, "%d\n", &t)

	for t > 0 {
		var n int
		fmt.Fscanf(reader, "%d\n", &n)

		s := (1 + n) * n / 2
		t_ := 1
		for t_ <= n {
			s -= 2 * t_
			t_ *= 2
		}

		fmt.Println(s)
		t--
	}
}

