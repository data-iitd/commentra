package main

import (
    "fmt"
    "strings"
)

func main() {
    for {
        input, _ := bufio.NewReader(os.Stdin).ReadString('\n')
        if input == ".\n" {
            break
        }
        a := [3]int{0, 1, 2}
        cnt := 0
        for i := 0; i < 3; i++ {
            for j := 0; j < 3; j++ {
                for k := 0; k < 3; k++ {
                    a[0], a[1], a[2] = i, j, k
                    ss := strings.Replace(input, "P", string(i), -1)
                    ss = strings.Replace(ss, "Q", string(j), -1)
                    ss = strings.Replace(ss, "R", string(k), -1)
                    if parse(ss) == 2 {
                        cnt++
                    }
                }
            }
        }
        fmt.Println(cnt)
    }
}

func parse(ss string) int {
    c := ss[0]
    if '0' <= c && c <= '2' {
        return int(c) - '0'
    }
    if c == '-' {
        return Not(parse(ss[1:]))
    }

    x := parse(ss[1:])
    c = ss[2]
    y := parse(ss[3:])
    return c == '*'? And(x, y) : Or(x, y)
}

func Not(x int) int {
    return 2 - x
}

func And(x, y int) int {
    if x*y == 0 {
        return 0
    }
    if x == 2 && y == 2 {
        return 2
    }
    return 1
}

func Or(x, y int) int {
    if x == 2 || y == 2 {
        return 2
    }
    if x == 1 || y == 1 {
        return 1
    }
    return 0
}

