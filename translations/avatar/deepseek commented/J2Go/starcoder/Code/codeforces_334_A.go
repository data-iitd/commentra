package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n, square, loop, div int
		i, j                  int
		odd, even             []int
	)

	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	fmt.Fscan(in, &n)
	square = n * n
	loop = square / n
	div = loop / 2

	for i = 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}

	for i = 1; i <= loop; i++ {
		for j = 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Fprint(out, odd[0], " ", even[len(even)-1], " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Fprint(out, even[0], " ", odd[len(odd)-1], " ")
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Fprintln(out)
	}

	out.Flush()
}

