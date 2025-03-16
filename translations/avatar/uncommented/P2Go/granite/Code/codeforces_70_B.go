
package main

import (
    "bufio"
    "fmt"
    "os"
    "regexp"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the value of n:")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the string:")
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    ans, sumL := 1, 0
    re := regexp.MustCompile(`[.?!]`)
    for _, s := range re.Split(str, -1) {
        s = strings.TrimSpace(s) + "."
        l := len(s)
        if l > 1 {
            if l > n {
                fmt.Println("Impossible")
                return
            }
            if sumL+l+(sumL > 0) > n {
                ans++
                sumL = l
            } else {
                sumL = sumL + l + (sumL > 0)
            }
        }
    }
    fmt.Println(ans)
}
