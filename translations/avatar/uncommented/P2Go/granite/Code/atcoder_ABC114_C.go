
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var N int

func aaa(n int) int {
    if n > N {
        return 0
    }
    ans := 1
    if len(strconv.Itoa(n)) == len(strconv.Itoa(N)) {
        ok := true
        for _, c := range strconv.Itoa(n) {
            if c!= '3' && c!= '5' && c!= '7' {
                ok = false
                break
            }
        }
        if ok {
            ans = 1
        }
    }
    for _, c := range "357" {
        ans += aaa(n*10 + int(c-'0'))
    }
    return ans
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        N, _ = strconv.Atoi(scanner.Text())
    }
    fmt.Println(aaa(0))
}

