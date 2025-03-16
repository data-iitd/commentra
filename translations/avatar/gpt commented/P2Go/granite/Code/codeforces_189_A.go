
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Read input and convert it into a list of integers
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    arr := strings.Split(input, " ")
    length, _ := strconv.Atoi(arr[0])
    arr = arr[1:]
    for i := 0; i < len(arr); i++ {
        arr[i], _ = strconv.Atoi(arr[i])
    }
    
    // Sort the next three elements (the lengths of the pieces) in ascending order
    sort.Ints(arr)
    
    // If the total length is divisible by the smallest piece length, print the maximum number of pieces
    if length%arr[0] == 0 {
        fmt.Println(length / arr[0])
        return
    }
    
    // Initialize the answer variable to keep track of the maximum pieces
    ans := 0
    
    // Case when the two smallest piece lengths are equal
    if arr[0] == arr[1] {
        k := 0
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for i := 0; i <= length/arr[2]; i++ {
            // Calculate the remaining length after using i pieces of the largest size
            check := length - i*arr[2]
            // Check if the remaining length can be completely divided by the smallest piece length
            if check >= 0 && check%arr[0] == 0 {
                k = check / arr[0]
                // Update the maximum pieces found
                ans = max(ans, k+i)
            }
        }
    } else {
        // Case when the two smallest piece lengths are different
        k := 0
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for i := 0; i <= length/arr[2]; i++ {
            // Iterate through the number of the second largest pieces that can fit into the ribbon
            for j := 0; j <= length/arr[1]; j++ {
                // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                check := length - i*arr[2] - j*arr[1]
                // Check if the remaining length can be completely divided by the smallest piece length
                if check >= 0 && check%arr[0] == 0 {
                    k = check / arr[0]
                    // Update the maximum pieces found
                    ans = max(ans, k+i+j)
                }
            }
        }
    }
    
    // Print the maximum number of pieces that can be obtained
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Call the function to execute the ribbon cutting logic
cutRibbon()