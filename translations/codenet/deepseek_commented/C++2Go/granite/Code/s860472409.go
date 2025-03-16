
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(read())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(read())
	}
	i := 0
	ans := 0
	count := 0
	for A[i+1]!= 0 {
		if A[i] == A[i+1] {
			count++
			if count%2!= 0 {
				ans++
			}
		} else {
			count = 0
		}
		i++
	}
	fmt.Println(ans)
}

func read() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

