
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 7007

type QUEUE struct {
	a, b, c, tot int
}

var (
	F    = [6][3]int{{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}}
	Hash = make([][]int, MOD)
)

func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

func main() {
	que := make(chan QUEUE, 10000)
	var Push QUEUE
	Push.tot = 0
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d%d", &Push.a, &Push.b, &Push.c)
	que <- Push
	for {
		Fro, ok := <-que
		if!ok {
			break
		}
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot)
			return
		}
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if!HASH(n) {
				continue
			}
			que <- Push
		}
	}
}

