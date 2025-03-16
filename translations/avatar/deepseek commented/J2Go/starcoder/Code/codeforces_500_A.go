package main

import "fmt"

func dfs(currpos int, arr []int, target int) bool {
    // Depth-first search method to find if the target position can be reached
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
    var n, goal int
    fmt.Scanf("%d %d", &n, &goal)
    arr := make([]int, n-1)
    for i := 0; i < n-1; i++ {
        fmt.Scanf("%d", &arr[i])
    }
    isFound := dfs(1, arr, goal)
    if isFound {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

