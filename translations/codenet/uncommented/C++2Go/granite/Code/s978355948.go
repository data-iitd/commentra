
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, X := readTwoInt()
	L := readNInt(N)
	i := 0
	d := 0
	for i = 0; i < N; i++ {
		d = d + L[i]
		if d > X {
			break
		}
	}
	fmt.Println(i + 1)
}

func readTwoInt() (int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	split := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(split[0])
	x, _ := strconv.Atoi(split[1])
	return n, x
}

func readNInt(n int) []int {
	res := make([]int, n)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		scanner.Scan()
		res[i], _ = strconv.Atoi(scanner.Text())
	}
	return res
}

