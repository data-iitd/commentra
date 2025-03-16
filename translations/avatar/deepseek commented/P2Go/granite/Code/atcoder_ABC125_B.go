

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])
	V := make([]int, N)
	C := make([]int, N)
	for i := 0; i < N; i++ {
		V[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])
	}
	for i := 0; i < N; i++ {
		C[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])
	}
	list := []int{0}
	ans := 0
	X := 0
	Y := 0
	for i := 0; i < N; i++ {
		if V[i]-C[i] > 0 {
			X = V[i]
			Y = C[i]
			list = append(list, X-Y)
		}
	}
	fmt.Println(sum(list))
}

func sum(list []int) int {
	ans := 0
	for i := 0; i < len(list); i++ {
		ans += list[i]
	}
	return ans
}

