

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
    writer := bufio.NewWriter(os.Stdout)

    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)

    a := make([]int, 1001)
    for i := 0; i < int(n); i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        aTemp = strings.TrimSpace(aTemp)
        aValue, err := strconv.ParseInt(aTemp, 10, 64)
        checkError(err)
        a[int(aValue)]++
    }

    max := 0
    for i := 1; i < 1001; i++ {
        if a[i] > max {
            max = a[i]
        }
    }

    if n%2 == 0 {
        if max <= n/2 {
            fmt.Fprintf(writer, "YES\n")
        } else {
            fmt.Fprintf(writer, "NO\n")
        }
    } else {
        if max <= n/2+1 {
            fmt.Fprintf(writer, "YES\n")
        } else {
            fmt.Fprintf(writer, "NO\n")
        }
    }

    writer.Flush()
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

These comments should provide a clear understanding of the logic behind each block of code.