
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(read(reader))
    h := make([]int, n)
    max := -1
    flag := 0

    // Loop to read heights and determine the maximum height
    for i := 0; i < n; i++ {
        h[i], _ = strconv.Atoi(read(reader))
        if max < h[i] {
            max = h[i]
        }
        if max-h[i] >= 2 {
            flag = 1
        }
    }

    // Output result based on the flag value
    if flag == 1 {
        fmt.Println("No") // If flag is set, print "No"
    } else {
        fmt.Println("Yes") // If flag is not set, print "Yes"
    }
}

func read(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine()
    return string(str)
}

