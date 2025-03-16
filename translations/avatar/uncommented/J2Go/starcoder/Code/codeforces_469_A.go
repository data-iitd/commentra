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
	fmt.Println("Enter the number of levels: ")
	level, _ := reader.ReadString('\n')
	level = strings.Replace(level, "\n", "", -1)
	levelInt, _ := strconv.Atoi(level)
	fmt.Println("Enter the number of elements: ")
	n, _ := reader.ReadString('\n')
	n = strings.Replace(n, "\n", "", -1)
	nInt, _ := strconv.Atoi(n)
	fmt.Println("Enter the elements: ")
	arr := make([]int, levelInt)
	for i := 0; i < levelInt; i++ {
		arr[i], _ = reader.ReadString('\n')
		arr[i] = strings.Replace(arr[i], "\n", "", -1)
		arr[i], _ = strconv.Atoi(arr[i])
	}
	fmt.Println("Enter the level2: ")
	level2, _ := reader.ReadString('\n')
	level2 = strings.Replace(level2, "\n", "", -1)
	level2Int, _ := strconv.Atoi(level2)
	fmt.Println("Enter the elements: ")
	arr2 := make([]int, level2Int)
	for i := 0; i < level2Int; i++ {
		arr2[i], _ = reader.ReadString('\n')
		arr2[i] = strings.Replace(arr2[i], "\n", "", -1)
		arr2[i], _ = strconv.Atoi(arr2[i])
	}
	arr3 := make([]int, nInt)
	j := 0
	for i := 0; i < nInt; i++ {
		arr3[i] = j
		j++
	}
	count := 0
	for i := 0; i < nInt; i++ {
		for x := 0; x < len(arr2); x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}
	if count == nInt {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

