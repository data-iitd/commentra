
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
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the size of the array:")
    size, _ := reader.ReadString('\n')
    size = strings.TrimSpace(size)
    n, _ := strconv.Atoi(size)

    array := make([]int, 3*n)
    for i := 0; i < 3*n; i++ {
        fmt.Printf("Enter element %d: ", i+1)
        element, _ := reader.ReadString('\n')
        element = strings.TrimSpace(element)
        array[i], _ = strconv.Atoi(element)
    }

    sort.Ints(array)

    head := len(array) - 2
    result := int64(0)
    for i := 0; i < n; i++ {
        result += int64(array[head])
        head -= 2
    }

    fmt.Println("The result is:", result)
}

