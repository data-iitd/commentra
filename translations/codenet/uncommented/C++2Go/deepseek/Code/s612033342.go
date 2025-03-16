package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func pow2(a int) int {
	ret := 1
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
}

func count(hw [][]int, a int, b int) int {
	sum := 0
	for i := 0; i < len(hw); i++ {
		for j := 0; j < len(hw[0]); j++ {
			if a&(1<<i) != 0 && b&(1<<j) != 0 && hw[i][j] == 1 {
				sum++
			}
		}
	}
	return sum
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	h, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	w, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	hw := make([][]int, h)
	for i := 0; i < h; i++ {
		hw[i] = make([]int, w)
		for j := 0; j < w; j++ {
			scanner.Scan()
			c := scanner.Text()
			if c == "#" {
				hw[i][j] = 1
			}
		}
	}
	sum := 0
	for i := 0; i < pow2(h); i++ {
		for j := 0; j < pow2(w); j++ {
			if count(hw, i, j) == k {
				sum++
			}
		}
	}
	fmt.Println(sum)
}
