

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(text)

    count := 0
    temp := number
    ans := 0

    for temp > 0 {
        temp /= 10
        count++
    }

    for i := 1; i <= count; i++ {
        if i == count {
            if i%2 == 1 {
                ans += (number - int(math.Pow(10, float64(i-1)))+1)
            }
        } else {
            if i == 1 {
                ans += 9
            } else if i%2 == 1 {
                ans += int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1)))
            }
        }
    }

    fmt.Println(ans)
}

