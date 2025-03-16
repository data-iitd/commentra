
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, new(int))
	var A []int
	for i := 0; i < N; i++ {
		A = append(A, int(strconv.Atoi(reader.ReadString()[:len(reader.ReadString()[:len(reader.ReadString())-1])])))
	}
	var fact [1000000]int
	fact[0] = 1
	for i := 1; i < 1000000; i++ {
		fact[i] = fact[i-1] * i % 1000000007
	}
	var inv [1000000]int
	inv[0] = 1
	for i := 1; i < 1000000; i++ {
		inv[i] = inv[i-1] * (i + 1) % 1000000007
	}
	var temp [1000000]int
	for i := 0; i < N; i++ {
		temp[i] = inv[i] + inv[N-1-i] - 1
	}
	var ans int
	for i := 0; i < N; i++ {
		ans += A[i] * temp[i] % 1000000007
	}
	ans = ans * fact[N] % 1000000007
	fmt.Println(ans)
}

