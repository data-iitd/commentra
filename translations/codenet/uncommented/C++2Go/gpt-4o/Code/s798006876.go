package main

import (
	"fmt"
)

const MAX_N = 1000

func main() {
	var m, nmi, nma int
	data := make([]int, MAX_N)

	for {
		_, err := fmt.Scan(&m, &nmi, &nma)
		if err != nil || nmi == 0 {
			break
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&data[i])
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

// <END-OF-CODE>
