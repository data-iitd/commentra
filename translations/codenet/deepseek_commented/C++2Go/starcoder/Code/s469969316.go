<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "strings"
)

func Not(x int) int {
    return 2-x
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

func parse() int {
    c := ss[it]
    it++
    if '0' <= c && c <= '2' {
        return c-'0'
    }
    if c == '-' {
        return Not(parse())
    }

    x := parse()
    c = ss[it]
    y := parse()
    it++
<<<<<<< HEAD
    if c == '*' {
        return And(x, y)
    }
    return Or(x, y)
}

func main() {
    var input string
    for {
        fmt.Scanln(&input)
        if input == "." {
            break
        }
        var ss string
        var a [3]int
=======
    return c == '*'? And(x, y) : Or(x, y)
}

func main() {
    for {
        input := strings.TrimSpace(readLine())
        if input == "." {
            break
        }

        var a [3]int
        var ss string
>>>>>>> 98c87cb78a (data updated)
        var it int
        var cnt int
        for i := 0; i < 3; i++ {
            for j := 0; j < 3; j++ {
                for k := 0; k < 3; k++ {
                    a[0], a[1], a[2] = i, j, k
                    ss = input
<<<<<<< HEAD
                    ss = strings.Replace(ss, "P", string(i), -1)
                    ss = strings.Replace(ss, "Q", string(j), -1)
                    ss = strings.Replace(ss, "R", string(k), -1)
=======
                    for i := range ss {
                        if ss[i] == 'P' {
                            ss[i] = byte(a[0] + '0')
                        }
                        if ss[i] == 'Q' {
                            ss[i] = byte(a[1] + '0')
                        }
                        if ss[i] == 'R' {
                            ss[i] = byte(a[2] + '0')
                        }
                    }
>>>>>>> 98c87cb78a (data updated)
                    it = 0
                    if parse() == 2 {
                        cnt++
                    }
                }
            }
        }
        fmt.Println(cnt)
    }
}

<<<<<<< HEAD
=======
// 
>>>>>>> 98c87cb78a (data updated)
