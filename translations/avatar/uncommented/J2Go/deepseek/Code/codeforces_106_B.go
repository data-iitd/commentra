package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	type Product struct {
		a, b, c, d int
	}

	var vec [1000]Product

	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &vec[i].a, &vec[i].b, &vec[i].c, &vec[i].d)
	}

	ans := 500
	ansprice := 20000

	for i := 0; i < n; i++ {
		fl := 1
		for j := 0; j < n; j++ {
			if vec[i].a < vec[j].a && vec[i].b < vec[j].b && vec[i].c < vec[j].c {
				fl = 0
			}
		}
		if fl == 1 {
			if vec[i].d < ansprice {
				ansprice = vec[i].d
				ans = i + 1
			}
		}
	}

	fmt.Fprintln(writer, ans)
	writer.Flush()
}

