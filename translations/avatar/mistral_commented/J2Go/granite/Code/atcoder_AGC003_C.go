
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
    fmt.Println("Enter the number of elements in the array:")
    N, _ := strconv.Atoi(reader.ReadLine()[0])
    var nums []int
    for i := 0; i < N; i++ {
        fmt.Println("Enter element", i+1, ":")
        num, _ := strconv.Atoi(reader.ReadLine()[0])
        nums = append(nums, num)
    }
    sort.Ints(nums)
    bin := 0
    diff := 0
    for _, num := range nums {
        if (bin%2)!= (num%2) {
            diff++
        }
        bin++
        bin %= 2
    }
    ans := diff / 2
    fmt.Println("The answer is:", ans)
}

