
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	square := n * n
	odd := make([]int, 0)
	even := make([]int, 0)

	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}

	loop := square / n
	div := loop / 2

	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Fprintf(writer, "%d %d ", odd[len(odd)-1], even[0])
				odd = odd[:len(odd)-1]
				even = even[1:]
			} else {
				fmt.Fprintf(writer, "%d %d ", even[len(even)-1], odd[0])
				odd = odd[1:]
				even = even[:len(even)-1]
			}
		}
		fmt.Fprintf(writer, "\n")
	}

	writer.Flush()
}

