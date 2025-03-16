
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
    fmt.Println("Enter the number of towers:")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the heights of the towers:")
    input := reader.ReadLine()
    heights := strings.Split(string(input), " ")
    towers := make([]int, n)
    for i := 0; i < n; i++ {
        towers[i], _ = strconv.Atoi(heights[i])
    }
    high := 1
    maxHigh := 1
    for i := 1; i < n; i++ {
        if towers[i] == towers[i-1] {
            high++
        } else {
            if high > maxHigh {
                maxHigh = high
            }
            high = 1
        }
    }
    if high > maxHigh {
        maxHigh = high
    }
    fmt.Println(maxHigh, n-maxHigh)
}
