

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
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
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.Atoi(strings.TrimSpace(nTemp))
    checkError(err)
    goalTemp, err := reader.ReadString('\n')
    checkError(err)
    goal, err := strconv.Atoi(strings.TrimSpace(goalTemp))
    checkError(err)
    arrTemp := strings.Split(strings.TrimSpace(nTemp), " ")
    var arr []int
    for i := 0; i < len(arrTemp)-1; i++ {
        arrItemTemp, err := strconv.Atoi(arrTemp[i])
        checkError(err)
        arrItem := arrItemTemp
        arr = append(arr, arrItem)
    }
    isFound := dfs(1, arr, goal)
    if isFound {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

These comments should provide a clear understanding of the code's logic and functionality.