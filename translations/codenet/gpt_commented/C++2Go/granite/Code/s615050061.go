
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Uncomment the following lines to read from a file
    // file, _ := os.Open("code.in")
    // defer file.Close()
    // reader := bufio.NewReader(file)

    // Read input values: number of operations and the operations string
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    s := readLine(reader)

    // Process each character in the input string
    f := make([]int64, n+1)
    g := make([]int, n+1)
    for i := 1; i <= n; i++ {
        // If the character is '+' or '-', update f and g arrays
        if s[i-1] == '+' || s[i-1] == '-' {
            f[i] = f[i-1] + (1 - 2*(s[i-1]-'+'))
            g[i] = g[i-1]
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i-1]
            g[i] = g[i-1] + (1 - 2*(s[i-1]-'<'))
        }
    }

    // Iterate backwards through the string to count valid combinations
    m := make(map[int64]int)
    var cnt int64
    for i := n; i > 0; i-- {
        m[f[i]]++ // Increment the count of the current f value
        // Update the counter with the number of valid combinations found
        cnt += int64(m[f[n]*int64(g[i-1])+f[i-1]])
    }

    // Output the final count of valid combinations
    fmt.Println(cnt)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

