
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
	fmt.Println("Enter the number of elements in the list")
	N, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the list")
	V := strings.Split(reader.ReadString('\n'), " ")
	V = strToInt(V)
	fmt.Println("Enter the elements of the list")
	C := strings.Split(reader.ReadString('\n'), " ")
	C = strToInt(C)
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

func strToInt(str []string) []int {
	var num []int
	for _, v := range str {
		n, _ := strconv.Atoi(v)
		num = append(num, n)
	}
	return num
}

func sum(list []int) int {
	ans := 0
	for _, v := range list {
		ans += v
	}
	return ans
}

