package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of strings")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the strings")
	arrs := make([]string, n)
	for i := 0; i < n; i++ {
		arrs[i], _ = reader.ReadString('\n')
	}
	fmt.Println("Enter the number of queries")
	m, _ := strconv.Atoi(reader.ReadString('\n'))
	length := make([]int, n)
	index := 0
	returnDex := 0
	for tmp := range arrs {
		dexG := strings.Index(arrs[tmp], "G")
		dexS := strings.Index(arrs[tmp], "S")
		if dexG > dexS {
			returnDex = -1
		}
		length[index] = dexS - dexG
		index++
	}
	set := make(map[int]bool)
	for len := range length {
		set[len] = true
	}
	if returnDex == -1 {
		fmt.Println(returnDex)
	} else {
		fmt.Println(len(set))
	}
}

