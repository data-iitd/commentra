package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n := parseInt(in.Text())
	square := n * n

	odd := []int{}
	even := []int{}

	// Separating numbers into odd and even lists
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}

	loop := square / n
	div := loop / 2

	// Nested loops to generate the pattern
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
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
}

func parseInt(s string) int {
	var res int
	fmt.Sscan(s, &res)
	return res
}

