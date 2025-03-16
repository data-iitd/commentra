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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }
    ans := 0
    ok := true
    for ok {
        for i := 0; i < n; i++ {
            if a[i]%2 == 1 {
                fmt.Println(ans)
                return
            }
            a[i] /= 2
        }
        ans++
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

