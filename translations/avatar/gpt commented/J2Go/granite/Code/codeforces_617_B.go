
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading an integer n from user input, which represents the number of elements
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Initializing a list to store the indices of elements that are equal to 1
    arr := make([]int, 0)

    // Looping through the input values to find indices of elements equal to 1
    for i := 0; i < n; i++ {
        // If the input value is 1, add the current index to the list
        a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        if a == 1 {
            arr = append(arr, i)
        }
    }

    // Checking if the list of indices is empty
    if len(arr) == 0 {
        // If the list is empty, print 0
        fmt.Println(0)
    } else {
        // If the list is not empty, initialize a result variable to 1
        result := int64(1)

        // Calculate the product of the differences between consecutive indices
        for i := 1; i < len(arr); i++ {
            result *= int64(arr[i] - arr[i-1])
        }

        // Print the final result
        fmt.Println(result)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

