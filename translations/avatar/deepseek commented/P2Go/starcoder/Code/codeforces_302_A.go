
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

    fmt.Println("Enter the number of elements in the array and the number of queries")
    n, m, err := readThreeNums(reader)
    checkError(err)

    sa := strings.Count(readNum(reader), "-")
    // Count the number of '-' characters in the input

    sa = min(n-sa, sa)
    // Set sa to the minimum of n - sa and sa, possibly normalizing sa

    ss := make([]string, m)
    // Initialize an empty list to store results

    for i := 0; i < m; i++ {
        a, b, err := readThreeNums(reader)
        checkError(err)

        b -= a
        // Subtract a from b

        if b%2 == 1 && b <= sa<<1 {
            ss[i] = "1\n"
        } else {
            ss[i] = "0\n"
        }
    }

    fmt.Print(strings.Join(ss, ""))
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c error) {
    aStr, err := readNum(reader)
    if err!= nil {
        return
    }
    a, err = strconv.Atoi(aStr)
    if err!= nil {
        return
    }
    bStr, err := readNum(reader)
    if err!= nil {
        return
    }
    b, err = strconv.Atoi(bStr)
    if err!= nil {
        return
    }
    return
}

func readNum(reader *bufio.Reader) (a string, b error) {
    a, b = reader.ReadString('\n')
    if b!= nil {
        return "", b
    }
    a = strings.TrimSpace(a)
    return
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

