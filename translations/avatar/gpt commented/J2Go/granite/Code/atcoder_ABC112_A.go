
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read the first input as an integer
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(readLine(reader))

    // Check if the input is 1
    if n == 1 {
        // If the input is 1, print "Hello World"
        fmt.Println("Hello World")
    } else {
        // If the input is not 1, read two more strings
        strs := readLineSlice(reader, 2)
        // Parse the two strings as integers and print their sum
        a, _ := strconv.Atoi(strs[0])
        b, _ := strconv.Atoi(strs[1])
        fmt.Println(a + b)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine()
    return string(str)
}

func readLineSlice(reader *bufio.Reader, n int) []string {
    var strs []string
    for i := 0; i < n; i++ {
        strs = append(strs, readLine(reader))
    }
    return strs
}

// END-OF-CODE