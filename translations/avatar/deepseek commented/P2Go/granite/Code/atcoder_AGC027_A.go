

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    // Define a reader to read input from the standard input

    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    // Read the value of n from input and convert it to an integer

    x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    // Read the value of x from input and convert it to an integer

    a := readLine(reader)
    // Read the list `a` from input as a single string

    aSplit := strings.Split(a, " ")
    // Split the string `a` into a slice of strings using space as the delimiter

    aList := make([]int, n)
    // Create a slice of integers with length n to store the elements of `a`

    for i := 0; i < n; i++ {
        aItem, _ := strconv.Atoi(aSplit[i])
        // Convert each string element in `aSplit` to an integer and store it in the corresponding index of `aList`

        aList[i] = aItem
    }

    sort.Ints(aList)
    // Sort the slice `aList` in ascending order

    ans := 0
    // Initialize the variable `ans` to store the result

    if aList[0] > x {
        fmt.Println(0)
        // Print 0 if the smallest element in `aList` is greater than `x`

        return
    }

    for i := 0; i < n; i++ {
        if aList[i] > x {
            x = 0
            break
        }

        x -= aList[i]
        ans++
    }

    if x!= 0 {
        ans--
    }

    fmt.Println(ans)
    // Print the value of `ans`
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

