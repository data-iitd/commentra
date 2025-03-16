

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(readerReadLine(reader)[0])
    m, _ := strconv.Atoi(readerReadLine(reader)[0])
    b := make([]int, n*2)
    for i := 0; i < n*2; i++ {
        b[i] = 1
    }
    b[0] = 0
    b[n-1] = 0
    b[n] = 0
    b[2*n-1] = 0
    for i := 0; i < m; i++ {
        r, _ := strconv.Atoi(readerReadLine(reader)[0])
        c, _ := strconv.Atoi(readerReadLine(reader)[0])
        b[r-1] = 0
        b[n+c-1] = 0
    }
    if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
        b[n/2] = 0
    }
    sum := 0
    for i := 0; i < n*2; i++ {
        sum += b[i]
    }
    fmt.Println(sum)
}

func readerReadLine(reader *bufio.Reader) []string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Split(string(str), " ")
    } else {
        return nil
    }
}

