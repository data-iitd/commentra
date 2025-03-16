package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter length of the ribbon:")
    length, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

    fmt.Println("Enter the three lengths of the ribbon:")
    arr := make([]int, 3)
    for i := 0; i < 3; i++ {
        arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    }

    sort.Ints(arr)

    if length%arr[0] == 0 {
        fmt.Println(length/arr[0])
        return
    }

    ans := 0
    if arr[0] == arr[1] {
        k := 0
        for i := 0; i <= length/arr[2]; i++ {
            check := length - i*arr[2]
            if check >= 0 && check%arr[0] == 0 {
                k = check/arr[0]
                ans = max(ans, k+i)
            }
        }
    } else {
        k := 0
        for i := 0; i <= length/arr[2]; i++ {
            for j := 0; j <= length/arr[1]; j++ {
                check := length - i*arr[2] - j*arr[1]
                if check >= 0 && check%arr[0] == 0 {
                    k = check/arr[0]
                    ans = max(ans, k+i+j)
                }
            }
        }
    }

    fmt.Println(ans)
}

