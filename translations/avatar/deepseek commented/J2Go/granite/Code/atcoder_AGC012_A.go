
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the input value `n` which represents the number of elements to process.
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Step 2: Read the array of size `3 * n` from the standard input.
    array := readLine(reader)
    split := strings.Split(array, " ")
    var arr []int
    for _, s := range split {
        i, _ := strconv.Atoi(s)
        arr = append(arr, i)
    }

    // Step 3: Sort the array in ascending order.
    sort(arr)

    // Step 4: Initialize a variable `head` to point to the second last element of the array.
    head := len(arr) - 2

    // Step 5: Initialize a variable `res` to store the result.
    var res int64

    // Step 6: Iterate `n` times, in each iteration:
    // - Add the value at the `head` position to `res`.
    // - Decrement `head` by 2.
    for i := 0; i < n; i++ {
        res += int64(arr[head])
        head -= 2
    }

    // Step 7: Print the result `res`.
    fmt.Println(res)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

func sort(arr []int) {
    for i := 0; i < len(arr); i++ {
        for j := i + 1; j < len(arr); j++ {
            if arr[i] > arr[j] {
                arr[i], arr[j] = arr[j], arr[i]
            }
        }
    }
}

