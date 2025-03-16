package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var m, nmi, nma int
	for {
		_, err := fmt.Scanf("%d %d %d", &m, &nmi, &nma)
		if err!= nil {
			break
		}
		data := make([]int, m)
		for i := 0; i < m; i++ {
			_, err := fmt.Scanf("%d", &data[i])
			if err!= nil {
				break
			}
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

