package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1e9 + 7

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)
	for t > 0 {
		t--
		var n, a, b int64
		fmt.Fscan(reader, &n, &a, &b)
		if n < a {
			fmt.Fprintln(writer, "No")
			continue
		}
		if a == b {
			if n%a == 0 {
				fmt.Fprintln(writer, "Yes")
			} else {
				fmt.Fprintln(writer, "No")
			}
			continue
		}
		x := b / (b - a)
		if n > x*a {
			fmt.Fprintln(writer, "Yes")
			continue
		}
		low := int64(1)
		high := x + 1
		ans := int64(1)
		for low <= high {
			mid := (low + high) / 2
			if mid*a < n {
				low = mid + 1
			} else {
				ans = mid
				high = mid - 1
			}
		}
		if n > (ans-1)*b && n < ans*a {
			fmt.Fprintln(writer, "No")
		} else {
			fmt.Fprintln(writer, "Yes")
		}
	}
}

