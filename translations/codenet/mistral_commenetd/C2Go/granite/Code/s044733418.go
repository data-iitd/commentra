

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
        input, _ := reader.ReadString('\n')
        array[i], _ = strconv.Atoi(input)
    }
    sort.Slice(array[:], func(i, j int) bool {
        return array[i] > array[j]
    })
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
    }
}

