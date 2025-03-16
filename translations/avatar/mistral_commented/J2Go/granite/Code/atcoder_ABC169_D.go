
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
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.ParseInt(strings.TrimSpace(text), 10, 64)

    sqrt := int(math.Sqrt(float64(number)))
    answer := 0

    for i := 2; i <= sqrt; i++ {
        count := 0
        for number%int64(i) == 0 {
            number /= int64(i)
            count++
        }
        for j := 1; count-j >= 0; j++ {
            count -= j
            answer++
        }
    }
    if number > 1 {
        answer++
    }

    fmt.Println(answer)
}

