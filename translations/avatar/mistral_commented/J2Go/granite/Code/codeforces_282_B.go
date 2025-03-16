
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
    fmt.Println("Enter the number of test cases:")
    nTemp, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nTemp))
    s1 := 0
    s2 := 0
    var ch []string
    flag := 0
    dif := 0
    for i := 0; i < n; i++ {
        fmt.Println("Enter the value of x:")
        xTemp, _ := reader.ReadString('\n')
        x, _ := strconv.Atoi(strings.TrimSpace(xTemp))
        fmt.Println("Enter the value of y:")
        yTemp, _ := reader.ReadString('\n')
        y, _ := strconv.Atoi(strings.TrimSpace(yTemp))
        temp1 := s1 + x
        temp2 := s2 + y
        if int(math.Abs(float64(temp1-temp2))) <= 500 {
            s1 += x
            ch = append(ch, "A")
            continue
        }
        if int(math.Abs(float64(temp1-s2))) <= 500 {
            s2 += y
            ch = append(ch, "G")
            continue
        }
        flag = 1
        break
    }
    if flag == 1 {
        fmt.Println(-1)
    } else {
        fmt.Println(strings.Join(ch, ""))
    }
}

