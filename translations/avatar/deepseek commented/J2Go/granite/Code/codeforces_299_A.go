

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the input value n, which represents the number of elements in the array.
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Step 2: Create an array 'a' of size n and read n elements from the input.
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Step 3: Sort the array 'a'.
    sort(a)

    // Step 4: Find the minimum element in the sorted array 'a'.
    min := a[0]

    // Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
    for _, value := range a {
        if value%min!= 0 {
            fmt.Println(-1)
            return
        }
    }

    // Step 6: If all elements are divisible, print the minimum element.
    fmt.Println(min)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    return ""
}

func sort(a []int) {
    for i := 0; i < len(a); i++ {
        for j := i + 1; j < len(a); j++ {
            if a[i] > a[j] {
                a[i], a[j] = a[j], a[i]
            }
        }
    }
}

