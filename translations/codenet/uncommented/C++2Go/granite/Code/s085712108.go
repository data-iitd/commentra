
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 7007

var (
	F    = [6][3]int{{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}}
	Hash = [MOD][]int{}
)

type Queue struct {
	a, b, c, tot int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d %d\n", &Queue{tot: 0}.a, &Queue{tot: 0}.b, &Queue{tot: 0}.c)
	que := []Queue{Queue{tot: 0}}
	for len(que) > 0 {
		fro := que[0]
		que = que[1:]
		if fro.a == fro.b && fro.b == fro.c {
			fmt.Println(fro.tot)
			return
		}
		for i := 0; i < 6; i++ {
			push := Queue{
				a:   fro.a + F[i][0],
				b:   fro.b + F[i][1],
				c:   fro.c + F[i][2],
				tot: fro.tot + 1,
			}
			n := push.a*10000 + push.b*100 + push.c
			if!hash(n) {
				continue
			}
			que = append(que, push)
		}
	}
}

func hash(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

