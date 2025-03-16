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

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int(nTemp)

    m := make([]int, n)
    f := make([]int, n)

    for i := 0; i < int(n); i++ {
        line, err := reader.ReadString('\n')
        checkError(err)
        line = strings.TrimRight(line, "\r\n")
        x, a, b := strings.Split(line, " ")

        a, err = strconv.ParseInt(a, 10, 64)
        checkError(err)

        b, err = strconv.ParseInt(b, 10, 64)
        checkError(err)

        a = int(a)
        b = int(b) + 1

        if x == "M" {
            m[a] += 2
            m[b] -= 2
        } else {
            f[a] += 2
            f[b] -= 2
        }
    }

    a, b, c := 0, 0, 0
    for i := 0; i < int(n); i++ {
        a += m[i]
        b += f[i]
        if min(a, b) > c {
            c = min(a, b)
        }
    }

    fmt.Println(c)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

