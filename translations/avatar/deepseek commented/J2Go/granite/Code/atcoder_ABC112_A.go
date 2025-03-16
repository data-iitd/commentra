

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading the number of inputs
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Processing the input based on the value of n
    if n == 1 {
        // Outputting "Hello World" if n is 1
        fmt.Println("Hello World")
    } else {
        // Reading two strings and calculating their sum if n is not 1
        strs := readLine(reader)
        arr := strings.Split(strs, " ")
        a, _ := strconv.Atoi(arr[0])
        b, _ := strconv.Atoi(arr[1])
        fmt.Println(a + b)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimSpace(string(str))
}

// End of code