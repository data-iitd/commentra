

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements:")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the difference threshold:")
    d, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the numbers:")
    nums := make([]int, n)
    for i := 0; i < n; i++ {
        num, _ := strconv.Atoi(reader.ReadLine())
        nums[i] = num
    }
    result := 0
    a := 0
    for i := 1; i < n; i++ {
        a = nums[i-1] - nums[i]
        if a >= 0 {
            result += a/d + 1
            nums[i] += (a/d + 1) * d
        }
    }
    fmt.Println(result)
}

