

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine()[2:])
	K, _ := strconv.Atoi(reader.ReadLine()[2:])
	S := make([]int, N)
	for i := 0; i < N; i++ {
		S[i], _ = strconv.Atoi(reader.ReadLine())
	}
	temp := 0
	ans := 1000000000
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
			ans = int(math.Min(float64(temp), float64(ans)))
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

