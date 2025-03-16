
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var s [10]int
    var err error
    var i int

    // Step 3: Read input numbers into the array
    for i = 0; i < 10; i++ {
        s[i], err = strconv.Atoi(reader.ReadString('\n'))
        if err!= nil {
            fmt.Println("Error reading input:", err)
            return
        }
    }

    // Step 4: Sort the array
    sort.Ints(s[:]) // Sort the array in ascending order

    // Step 5: Print the last four numbers of the sorted array
    for i = 9; i > 6; i-- {
        fmt.Println(s[i]) // Print the last four numbers
    }
}

