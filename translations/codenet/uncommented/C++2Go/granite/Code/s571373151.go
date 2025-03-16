
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

    nTemp := strings.Split(readLine(reader), " ")

    n, err := strconv.ParseInt(nTemp[0], 10, 64)
    checkError(err)

    m, err := strconv.ParseInt(nTemp[1], 10, 64)
    checkError(err)

    foods := make([]int, int(m))

    for i := 0; i < int(n); i++ {
        kTemp := strings.Split(readLine(reader), " ")

        k, err := strconv.ParseInt(kTemp[0], 10, 64)
        checkError(err)

        for j := 0; j < int(k); j++ {
            tempTemp := strings.Split(readLine(reader), " ")

            temp, err := strconv.ParseInt(tempTemp[0], 10, 64)
            checkError(err)

            foods[int(temp)-1]++
        }
    }

    ans := 0

    for _, elem := range foods {
        if elem == n {
            ans++
        }
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}
