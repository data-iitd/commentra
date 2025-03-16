
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscanln(reader, &N, &M)
	H := make([]int, N)
	for i := 0; i < N; i++ {
<<<<<<< HEAD
		fmt.Fscan(reader, &H[i])
=======
		fmt.Fscanln(reader, &H[i])
>>>>>>> 98c87cb78a (data updated)
	}
	G := make([][]int, N)
	for i := 0; i < N; i++ {
		G[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		var u, v int
<<<<<<< HEAD
		fmt.Fscan(reader, &u, &v)
=======
		fmt.Fscanln(reader, &u, &v)
>>>>>>> 98c87cb78a (data updated)
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

// 