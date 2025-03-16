package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to check if it is possible to distribute weights
func check(m int, wei int, book []int) bool {
    tmp := wei // Temporary variable to hold the remaining weight
    m-- // Decrease the number of available books by one
    for i := 0; i < len(book); i++ {
        // If the current weight exceeds the available weight
        if tmp < book[i] {
            // If there are still books left to use
            if m > 0 {
                m-- // Use one book
                tmp = wei // Reset the temporary weight to the original weight
                // Check again if the current weight exceeds the available weight
                if tmp < book[i] {
                    return false // Not possible to distribute
                }
            } else {
                return false // No books left to use
            }
        }
        // Deduct the current book's weight from the temporary weight
        tmp -= book[i]
    }
    return true // Successfully distributed the weights
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        // Read input until m is zero
        m, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        if err!= nil || m == 0 {
            break
        }
        n, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        if err!= nil {
            break
        }
        book := make([]int, n)
        for i := 0; i < n; i++ {
            tmp, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
            if err!= nil {
                break
            }
            book[i] = tmp
        }

        /*
        // Uncomment this block to check for multiple weight distributions
        for {
            tmp, err := strconv.Atoi(strings.TrimSpace(readLine(reader)))
            if err!= nil {
                break
            }
            if check(m, tmp, book) {
                fmt.Println("YES")
            } else {
                fmt.Println("NO")
            }
        }
        */

        l := 0 // Lower bound for binary search
        r := 1500000 // Upper bound for binary search
        ans := 0 // Variable to store the answer
        // Perform binary search to find the maximum weight that can be distributed
        for {
            // Check if the middle weight can be distributed
            if check(m, (l+r)/2, book) {
                ans = (l + r) / 2 // Update answer
                // If the upper bound equals the middle, break the loop
                if r == (l + r) / 2 {
                    break
                }
                r = (l + r) / 2 // Move the upper bound down
            } else {
                // If the lower bound equals the middle, break the loop
                if l == (l + r) / 2 {
                    break
                }
                l = (l + r) / 2 // Move the lower bound up
            }
        }
        fmt.Println(ans) // Output the maximum weight that can be distributed
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

