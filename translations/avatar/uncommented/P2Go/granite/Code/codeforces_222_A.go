
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
    fmt.Println("Enter the value of n:")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))
    fmt.Println("Enter the value of k:")
    k, _ := reader.ReadString('\n')
    k, _ = strconv.Atoi(strings.TrimSpace(k))
    fmt.Println("Enter the elements of the array:")
    elems, _ := reader.ReadString('\n')
    elems = strings.TrimSpace(elems)
    elems = strings.Replace(elems, " ", "", -1)
    elems = strings.Replace(elems, "\n", "", -1)
    elems = strings.Replace(elems, "\r", "", -1)
    elems_arr := strings.Split(elems, "")
    all_same := func(arr []string) bool {
        for i := 1; i < len(arr); i++ {
            if arr[i]!= arr[0] {
                return false
            }
        }
        return true
    }
    if all_same(elems_arr) {
        fmt.Println(0)
        return
    }
    if k == 1 {
        fmt.Println(-1)
        return
    }
    if!all_same(elems_arr[k-1:]) {
        fmt.Println(-1)
        return
    }
    target := elems_arr[len(elems_arr)-1]
    to_delete := elems_arr[:k-1]
    for len(to_delete) > 0 && to_delete[len(to_delete)-1] == target {
        to_delete = to_delete[:len(to_delete)-1]
    }
    fmt.Println(len(to_delete))
}
