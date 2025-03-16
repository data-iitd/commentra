
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
    fmt.Println("Enter the length of the ribbon and the three colors of the ribbon:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    length, _ := strconv.Atoi(input)
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    colors := strings.Split(input, " ")
    var arr [3]int
    for i := 0; i < 3; i++ {
        arr[i], _ = strconv.Atoi(colors[i])
    }
    if length%arr[0] == 0 {
        fmt.Println(length / arr[0])
        return
    }
    ans := 0
    if arr[0] == arr[1] {
        k := 0
        for i := 0; i <= length/arr[2]; i++ {
            check := length - i*arr[2]
            if check >= 0 && check%arr[0] == 0 {
                k = check / arr[0]
                ans = int(math.Max(float64(ans), float64(k+i)))
            }
        }
    } else {
        k := 0
        for i := 0; i <= length/arr[2]; i++ {
            for j := 0; j <= length/arr[1]; j++ {
                check := length - i*arr[2] - j*arr[1]
                if check >= 0 && check%arr[0] == 0 {
                    k = check / arr[0]
                    ans = int(math.Max(float64(ans), float64(k+i+j)))
                }
            }
        }
    }
    fmt.Println(ans)
}
