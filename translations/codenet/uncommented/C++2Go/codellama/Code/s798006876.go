package main

import "fmt"

func main() {
	var m, nmi, nma int
	for {
		fmt.Scan(&m, &nmi, &nma)
		if nmi == 0 {
			break
		}
		data := make([]int, m)
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

