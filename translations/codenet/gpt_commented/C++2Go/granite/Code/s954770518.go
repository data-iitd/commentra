
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    // Declare an array to hold 10 integers
    var s [10]int

    // Input 10 integers from the user
    reader := bufio.NewReader(os.Stdin)
    for i := 0; i < 10; i++ {
        input, _ := reader.ReadString('\n')
        s[i], _ = strconv.Atoi(input)
    }

    // Sort the array of integers in ascending order
    sort.Ints(s[:])

    // Print the three largest integers from the sorted array
    for i := 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}

