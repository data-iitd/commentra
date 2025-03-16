<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        input := scanner.Text()
        if input == "." {
            break
        }
        var a [3]int
        var ss string
        var it int
        var cnt int
        for i := 0; i < 3; i++ {
            for j := 0; j < 3; j++ {
                for k := 0; k < 3; k++ {
                    a[0], a[1], a[2] = i, j, k
                    ss = input
                    for i, c := range ss {
                        if c == 'P' {
                            ss = ss[:i] + string(a[0]) + ss[i+1:]
                        }
                        if c == 'Q' {
                            ss = ss[:i] + string(a[1]) + ss[i+1:]
                        }
                        if c == 'R' {
                            ss = ss[:i] + string(a[2]) + ss[i+1:]
                        }
                    }
                    it = 0
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
    c := ss[it]
    if '0' <= c && c <= '2' {
        it++
        return int(c) - '0'
    }
    if c == '-' {
        it++
        return Not(parse(ss))
    }
    x := parse(ss)
    c = ss[it]
    y := parse(ss)
    it++
    if c == '*' {
        return And(x, y)
    }
    return Or(x, y)
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

