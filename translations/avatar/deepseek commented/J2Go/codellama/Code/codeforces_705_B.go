package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t int
	fmt.Scan(&t)
	arr := make([]int, t)
	for i := 0; i < t; i++ {
		fmt.Scan(&arr[i])
	}
	prevWinner := 0
	for i := 0; i < t; i++ {
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
		}
		if prevWinner == 2 || prevWinner == 0 {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2)
				prevWinner = 2
			} else {
				fmt.Println(1)
				prevWinner = 1
			}
		} else {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1)
				prevWinner = 1
			} else {
				fmt.Println(2)
				prevWinner = 2
			}
		}
	}
}

