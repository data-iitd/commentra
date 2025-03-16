
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    N := int32(NTemp)

    count := 0
    temp := N

    for temp > 0 {
        temp /= 10
        count++
    }

    ans := 0

    for i := 1; i <= count; i++ {
        if i == count {
            if i%2 == 1 {
                ans += int(N-pow(10, i-1)+1)
            }
        } else {
            if i == 1 {
                ans += 9
            } else if i%2 == 1 {
                ans += int(pow(10, i) - pow(10, i-1))
            }
        }
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func pow(x, n int32) int32 {
    result := int32(1)
    for i := int32(0); i < n; i++ {
        result *= x
    }
    return result
}

