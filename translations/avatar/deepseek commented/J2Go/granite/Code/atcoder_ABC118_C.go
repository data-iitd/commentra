

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of integers: ")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))

    if n == 1 {
        fmt.Print("Enter the integer: ")
        num, _ := reader.ReadString('\n')
        num, _ = strconv.Atoi(strings.TrimSpace(num))
        fmt.Println(num)
        return
    }

    var a []int
    for i := 0; i < n; i++ {
        fmt.Print("Enter integer ", i+1, ": ")
        num, _ := reader.ReadString('\n')
        num, _ = strconv.Atoi(strings.TrimSpace(num))
        a = append(a, num)
    }

    sort.Ints(a)

    if a[len(a)-1] == 0 {
        fmt.Println(0)
        return
    }

    var ans int
    for {
        if len(a) == 1 {
            ans = a[0]
            break
        }
        a = func(a []int) []int {
            var min int
            for i := 0; i < len(a); i++ {
                if a[i] == 0 {
                    a = append(a[:i], a[i+1:]...)
                    i--
                } else {
                    if min!= 0 {
                        a[i] = a[i] % min
                        if a[i] == 1 {
                            fmt.Println(1)
                            return nil
                        }
                    } else {
                        min = a[i]
                    }
                }
            }
            sort.Ints(a)
            return a
        }(a)
    }

    fmt.Println(ans)
}

func func(a []int) []int {
    var min int
    for i := 0; i < len(a); i++ {
        if a[i] == 0 {
            a = append(a[:i], a[i+1:]...)
            i--
        } else {
            if min!= 0 {
                a[i] = a[i] % min
                if a[i] == 1 {
                    fmt.Println(1)
                    return nil
                }
            } else {
                min = a[i]
            }
        }
    }
    sort.Ints(a)
    return a
}

