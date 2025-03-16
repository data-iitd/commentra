

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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    list := make([]int64, n)
    for i := 0; i < n; i++ {
        list[i], _ = strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    }
    odd := make([]int64, 0)
    sum := int64(0)
    for _, v := range list {
        if v%2 == 0 {
            sum += v
        } else {
            odd = append(odd, v)
        }
    }
    sort.Slice(odd, func(i, j int) bool {
        return odd[i] < odd[j]
    })
    for _, v := range odd {
        sum += v
    }
    if len(odd)%2!= 0 {
        sum -= odd[0]
    }
    fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!