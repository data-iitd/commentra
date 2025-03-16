
package main

import (
    "bufio"
    "fmt"
    "log"
    "os"
    "sort"
    "strconv"
)

// Function to compare two integers for sorting
func compare(a, b int) int {
    // Return the difference between b and a for descending order
    return b - a
}

func main() {
    // Declare an array of integers and a variable for iteration
    var array [10]int
    var i int

    // Read 10 integers from standard input into the array
    scanner := bufio.NewScanner(os.Stdin)
    for i = 0; i!= 10; i++ {
        scanner.Scan()
        num, err := strconv.Atoi(scanner.Text())
        if err!= nil {
            log.Fatal(err)
        }
        array[i] = num
    }

    // Sort the array in descending order using sort.Slice and the compare function
    sort.Slice(array[:], func(i, j int) bool {
        return compare(array[i], array[j]) > 0
    })

    // Print the first 3 elements of the sorted array
    for i = 0; i!= 3; i++ {
        fmt.Println(array[i])
    }
}

