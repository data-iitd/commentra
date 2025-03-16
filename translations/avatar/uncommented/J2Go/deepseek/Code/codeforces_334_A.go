package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)

	var n int
	in.Scan()
	fmt.Sscan(in.Text(), &n)
	square := n * n
	odd := []int{}
	even := []int{}
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}
	loop := square / n
	div := loop / 2
	fmt.Println(div)
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Fprintf(pw, "%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Fprintf(pw, "%d %d ", even[0], odd[len(odd)-1])
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Fprintln(pw)
	}
	pw.Flush()
}

