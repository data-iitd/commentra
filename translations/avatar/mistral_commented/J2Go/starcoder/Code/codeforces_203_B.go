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
	fmt.Println("Enter the size of the grid:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	N, _ := strconv.Atoi(input)
	fmt.Println("Enter the number of stones to be placed on the grid:")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	M, _ := strconv.Atoi(input)
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}
	fmt.Println("Enter the coordinates of the stones to be placed on the grid:")
	for m := 1; m <= M; m++ {
		input, _ = reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		x, _ := strconv.Atoi(input)
		input, _ = reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		y, _ := strconv.Atoi(input)
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				black[xx][yy]++
			}
		}
	}
	for m := 1; m <= M; m++ {
		for xx := 1; xx <= N+1; xx++ {
			for yy := 1; yy <= N+1; yy++ {
				if black[xx][yy] == 9 {
					fmt.Println(m)
					return
				}
			}
		}
	}
	fmt.Println("-1")
}

