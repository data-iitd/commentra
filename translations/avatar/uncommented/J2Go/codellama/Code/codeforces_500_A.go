
package main

import (
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
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	goal, _ := strconv.Atoi(sc.Text())
	arr := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text())
	}
	isFound := dfs(1, arr, goal)
	if isFound {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
	sc.Close()
}

