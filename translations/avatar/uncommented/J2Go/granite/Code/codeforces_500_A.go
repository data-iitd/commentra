
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func dfs(currpos int, arr []int, target int) bool {
	if currpos == target {
		return true
	}
	if currpos == len(arr)+1 {
		return false
	}
	teleport := dfs(currpos+arr[currpos-1], arr, target)
	if teleport {
		return true
	}
	return false
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	goal, _ := strconv.Atoi(reader.ReadLine()[4 : len(reader.ReadLine())])
	arr := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	}
	isFound := dfs(1, arr, goal)
	if isFound {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

