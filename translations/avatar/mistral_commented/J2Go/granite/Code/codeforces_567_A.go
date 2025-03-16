
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
    fmt.Print("Enter the size of the array: ")
    size, _ := reader.ReadString('\n')
    size, _ = strconv.Atoi(strings.TrimSpace(size))
    array := make([]int, size)
    fmt.Println("Enter the elements of the array:")
    for i := 0; i < size; i++ {
        element, _ := reader.ReadString('\n')
        element, _ = strconv.Atoi(strings.TrimSpace(element))
        array[i] = element
    }
    max := 0
    min := 0
    for i := 0; i < size; i++ {
        max = int(math.Max(float64(array[i]-array[0]), float64(array[size-1]-array[i])))
        if i == 0 {
            min = array[i+1] - array[i]
        } else if i == size-1 {
            min = array[i] - array[i-1]
        } else {
            min = int(math.Min(float64(array[i]-array[i-1]), float64(array[i+1]-array[i])))
        }
        fmt.Printf("Minimum difference: %d, Maximum difference: %d\n", min, max)
    }
}

