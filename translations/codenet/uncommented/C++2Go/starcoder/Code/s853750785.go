
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
	var N, M int
	fmt.Fscanln(reader, &N, &M)
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanln(reader, &H[i])
	}
	G := make([][]int, N)
	for i := 0; i < N; i++ {
		G[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Fscanln(reader, &u, &v)
		u--
		v--
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}
	ans := 0
	for u := 0; u < N; u++ {
		flag := true
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false
				break
			}
		}
		if flag {
			ans++
		}
	}
	fmt.Println(ans)
}

