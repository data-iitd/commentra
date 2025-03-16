
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var array [10]int
    for i := 0; i < 10; i++ {
        text, _ := reader.ReadString('\n')
        number, _ := strconv.Atoi(text)
        array[i] = number
    }
    sort.Slice(array[:], func(i, j int) bool {
        return array[i] > array[j]
    })
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
    }
}

