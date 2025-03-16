
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

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    first_multiple_input := strings.Split(readLine(reader), " ")

    x1Temp, err := strconv.ParseInt(first_multiple_input[0], 10, 64)
    checkError(err)
    x1 := int(x1Temp)

    y1Temp, err := strconv.ParseInt(first_multiple_input[1], 10, 64)
    checkError(err)
    y1 := int(y1Temp)

    x2Temp, err := strconv.ParseInt(first_multiple_input[2], 10, 64)
    checkError(err)
    x2 := int(x2Temp)

    y2Temp, err := strconv.ParseInt(first_multiple_input[3], 10, 64)
    checkError(err)
    y2 := int(y2Temp)

    result := kangaroo(x1, y1, x2, y2)

    fmt.Fprintf(writer, "%d %d %d %d\n", result[0], result[1], result[2], result[3])

    writer.Flush()
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

func kangaroo(x1 int, y1 int, x2 int, y2 int) []int {
    if x1 == x2 {
        dif := abs(y1 - y2)
        return []int{x1 + dif, y1, x1 + dif, y2}
    } else if y1 == y2 {
        dif := abs(x1 - x2)
        return []int{x1, y1 + dif, x2, y1 + dif}
    } else if abs(x1 - x2) == abs(y1 - y2) {
        return []int{x1, y2, x2, y1}
    } else {
        return []int{-1, -1, -1, -1}
    }
}

func abs(n int) int {
    if n < 0 {
        return -n
    }
    return n
}

