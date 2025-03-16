
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, K int
	fmt.Fscanf(reader, "%d %d\n", &N, &K)
	S := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &S[i])
	}
	var temp, ans int = 0, 10000000000
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			ans = int(math.Min(float64(math.Abs(temp)), float64(ans)))
		}
		fmt.Println(ans)
	} else if N-K!= 0 {
		for i := 0; i <= N-K; i++ {
			min := S[i]
			max := S[i+K-1]
			if min < 0 && max > 0 {
				temp = int(math.Min(float64(2*(-min)+max), float64((-min)+2*max)))
			} else {
				temp = int(math.Max(float64(math.Abs(min)), float64(math.Abs(max))))
			}
			ans = int(math.Min(float64(ans), float64(temp)))
		}
		fmt.Println(ans)
	} else {
		min := S[0]
		max := S[N-1]
		if min < 0 && max > 0 {
			fmt.Println(int(math.Min(float64(2*(-min)+max), float64((-min)+2*max))))
		} else {
			fmt.Println(int(math.Max(float64(math.Abs(min)), float64(math.Abs(max)))))
		}
	}
}
