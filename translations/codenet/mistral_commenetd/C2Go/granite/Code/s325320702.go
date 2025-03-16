
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var l, r, d int64
	fmt.Fscanf(reader, "%d\n", &l)
	fmt.Fscanf(reader, "%d\n", &r)
	fmt.Fscanf(reader, "%d\n", &d)

	ans := int64(0)
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	fmt.Println(ans)
}

The above Go code reads the input values for l, r, and d, and then calculates the number of integers between l and r (inclusive) that are divisible by d. The result is printed to the standard output.