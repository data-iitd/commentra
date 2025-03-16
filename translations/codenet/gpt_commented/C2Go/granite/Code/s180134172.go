
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n, k int
    var p []int
    var i, j, l, m, o int = 0, 0, 0, 0, 0, 0

    // Read the number of elements (n) and the number of smallest elements to sum (k)
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    inputSlice := strings.Split(input, ",")
    n, _ = strconv.Atoi(inputSlice[0])
    k, _ = strconv.Atoi(inputSlice[1])

    // Read n integers into the array p
    for i = 0; i < n; i++ {
        input, _ := reader.ReadString('\n')
        input = strings.TrimSpace(input)
        input = strings.Replace(input, "\n", "", -1)
        input = strings.Replace(input, " ", "", -1)
        p = append(p, 0)
        p[i], _ = strconv.Atoi(input)
    }

    // Selection sort algorithm to sort the array p in ascending order
    for i = 0; i < n; i++ {
        l = i // Assume the minimum is the first element
        for j = i + 1; j < n; j++ {
            // Update l if a smaller element is found
            if p[j] < p[l] {
                l = j
            }
        }
        // Swap the found minimum element with the first element
        if l!= i {
            m = p[i]
            p[i] = p[l]
            p[l] = m
        }
    }

    // Calculate the sum of the first k smallest elements in the sorted array
    for i = 0; i < k; i++ {
        o += p[i]
    }

    // Print the result: the sum of the k smallest elements
    fmt.Println(o)
}

