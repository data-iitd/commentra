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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of K")
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	S := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		S[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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

