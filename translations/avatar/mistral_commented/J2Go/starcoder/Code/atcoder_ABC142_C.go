package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var A int
	var idorder map[int]int
	var i int
	var j int
	var s string
	var err error
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	N, err = strconv.Atoi(scanner.Text())
	if err!= nil {
		fmt.Println(err)
		return
	}
	idorder = make(map[int]int)
	for i = 1; i <= N; i++ {
		A, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Println(err)
			return
		}
		idorder[A] = i
	}
	for i = 1; i <= N; i++ {
		fmt.Print(idorder[i], " ")
	}
	fmt.Println()
}

