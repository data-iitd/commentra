package main

import (
    "fmt"
    "sort"
    "os"
    "bufio"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the array")
    n, _ := strconv.Atoi(reader.ReadString('\n'))
    fmt.Println("Enter the value of k")
    k, _ := strconv.Atoi(reader.ReadString('\n'))
    fmt.Println("Enter the elements of the array")
    var arr []int
    for i := 0; i < n; i++ {
        var temp int
        temp, _ = strconv.Atoi(reader.ReadString('\n'))
        arr = append(arr, temp)
    }
    sort.Ints(arr)
    var ans int = 1000000001
    for i := 0; i + k - 1 < n; i++ {
        diff := arr[i+k-1] - arr[i]
        if diff < ans {
            ans = diff
        }
    }
    fmt.Println(ans)
}

