<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(readLine(reader))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a_item, _ := strconv.Atoi(readLine(reader))
        a[i] = a_item
    }

    abs_a := make([]int, n)
    copy(abs_a, a)
    for i := 0; i < n; i++ {
        if abs_a[i] < 0 {
            abs_a[i] = -abs_a[i]
        }
    }

    ans := 0
    min := abs_a[0]
    for _, e := range abs_a {
        ans += e
        if min > e {
            min = e
        }
    }

    num_negative := 0
    for _, e := range a {
        if e < 0 {
            num_negative++
        }
    }

    if num_negative%2!= 0 {
        ans -= min * 2
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

