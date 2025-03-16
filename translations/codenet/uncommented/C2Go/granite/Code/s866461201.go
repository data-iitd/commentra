
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fd := make([]int, 6)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < n; i++ {
		scanner.Scan()
		height, _ := strconv.ParseFloat(scanner.Text(), 64)
		if height >= 185.0 {
			fd[5]++
		} else if height >= 180.0 {
			fd[4]++
		} else if height >= 175.0 {
			fd[3]++
		} else if height >= 170.0 {
			fd[2]++
		} else if height >= 165.0 {
			fd[1]++
		} else {
			fd[0]++
		}
	}
	for i, v := range fd {
		fmt.Printf("%d:", i+1)
		for j := 0; j < v; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
}

