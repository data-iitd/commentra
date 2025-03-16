
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
    a, _ := strconv.Atoi(readLine(reader))
    b, _ := strconv.Atoi(readLine(reader))
    c, _ := strconv.Atoi(readLine(reader))
    d, _ := strconv.Atoi(readLine(reader))

    if c > b {
        fmt.Println(0)
    } else if a > d {
        fmt.Println(0)
    } else if a < c {
        fmt.Println(math.Min(float64(b), float64(d)) - float64(c))
    } else {
        l := []int{a, b, c, d}
        sort.Ints(l)
        fmt.Println(l[2] - l[1])
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

// Define a function for reading input from the standard input stream

