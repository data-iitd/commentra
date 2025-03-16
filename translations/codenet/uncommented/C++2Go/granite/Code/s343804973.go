
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	N, M, Mod int64
	C, Pre, F  [310][310]int64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d%d%d\n", &N, &M, &Mod)
	C[0][0] = 1
	for i := 1; i <= N; i++ {
		C[i][0] = C[i][i] = 1
		for j := 1; j < i; j++ {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % Mod
		}
	}
	for i := 0; i <= M; i++ {
		F[1][i] = 1
		Pre[1][i] = M - i + 1
	}
	for i := 2; i <= N+1; i++ {
		for j := 0; j <= M; j++ {
			for k := 1; k < i; k++ {
				F[i][j] = (F[i][j] + F[i-k][j]*Pre[k][j+1]%Mod*C[i-2][k-1]) % Mod
			}
		}
		for j := M; j >= 0; j-- {
			Pre[i][j] = (Pre[i][j+1] + F[i][j]) % Mod
		}
	}
	fmt.Println(F[N+1][0])
}

