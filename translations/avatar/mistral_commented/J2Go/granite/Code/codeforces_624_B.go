

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
    fmt.Print("Enter the number of elements in the array: ")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))

    arr := make([]int64, n)
    for i := 0; i < n; i++ {
        fmt.Print("Enter element ", i+1, ": ")
        element, _ := reader.ReadString('\n')
        element, _ = strconv.ParseInt(strings.TrimSpace(element), 10, 64)
        arr[i] = element
    }

    sort.Slice(arr, func(i, j int) bool {
        return arr[i] < arr[j]
    })

    count := int64(arr[n-1])
    for i := n - 2; i >= 0; i-- {
        if arr[i] < arr[i+1] {
            count += arr[i]
        } else {
            for arr[i] >= arr[i+1] {
                arr[i]--
            }
            if arr[i] > 0 {
                count += arr[i]
            }
        }
    }

    fmt.Println("The final count is:", count)
}

