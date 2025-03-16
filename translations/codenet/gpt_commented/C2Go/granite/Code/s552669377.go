
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables
    var i, n int
    var min, max, sum int64 = 1000000, -1000000, 0
    var tmp int
    var reader *bufio.Reader = bufio.NewReader(os.Stdin)
    var err error

    // Read the number of integers to be processed
    n, err = strconv.Atoi(read(reader))
    if err!= nil {
        panic(err)
    }

    // Loop to read n integers
    for i = 0; i < n; i++ {
        // Read the next integer
        tmp, err = strconv.Atoi(read(reader))
        if err!= nil {
            panic(err)
        }

        // Update min if the current number is smaller
        if min > int64(tmp) {
            min = int64(tmp)
        }

        // Update max if the current number is larger
        if max < int64(tmp) {
            max = int64(tmp)
        }

        // Add the current number to the sum
        sum += int64(tmp)
    }

    // Print the minimum, maximum, and sum of the numbers
    fmt.Printf("%d %d %d\n", min, max, sum)
}

func read(reader *bufio.Reader) string {
    var input string
    var err error

    if input, err = reader.ReadString('\n'); err!= nil {
        panic(err)
    }

    return input
}

