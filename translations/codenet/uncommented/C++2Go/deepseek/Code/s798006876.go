package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX_N = 1e3

var data [MAX_N]int

func main() {
	in := bufio.NewScanner(os.Stdin)
	for in.Scan() {
		var m, nmi, nma int
		fmt.Sscanf(in.Text(), "%d %d %d", &m, &nmi, &nma)
		if nmi == 0 {
			break
		}
		for i := 0; i < m; i++ {
			in.Scan()
			fmt.Sscanf(in.Text(), "%d", &data[i])
		}
		ma := 0
		ans := 0
		for i := nmi - 1; i < nma; i++ {
			if ma <= data[i]-data[i+1] {
				ans = i + 1
				ma = data[i] - data[i+1]
			}
		}
		fmt.Println(ans)
	}
}

