

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
    fmt.Println("Enter the length of the array:")
    len, _ := reader.ReadString('\n')
    len, _ = strconv.Atoi(strings.TrimSpace(len))
    a := make([]int, len)
    fmt.Println("Enter the elements of the array:")
    for i := 0; i < len; i++ {
        num, _ := reader.ReadString('\n')
        num, _ = strconv.Atoi(strings.TrimSpace(num))
        a[i] = num
    }
    l := 0
    r := 0
    flag := false
    isTrue := false
    for i := 0; i < len; i++ {
        if a[i]!= i+1 &&!flag {
            l = i + 1
            flag = true
            continue
        }
        if a[i]!= i+1 && flag {
            r = i + 1
            if (a[r-1]-a[r-2]) > 0 {
                isTrue = true
                break
            }
        }
    }
    if!isTrue {
        fmt.Println(l, r)
    } else {
        fmt.Println("0 0")
    }
}

