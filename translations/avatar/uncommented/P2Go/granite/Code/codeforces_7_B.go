
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
    var t, m int
    var err error
    var op []string
    var alocuente []int
    ind := 1
    fmt.Fscanf(reader, "%d %d\n", &t, &m)
    alocuente = make([]int, m)
    for i := 0; i < t; i++ {
        op, err = reader.ReadString('\n')
        op = strings.Split(op, " ")
        if op[0] == "alloc" {
            pos := 0
            for j := 0; j < m; j++ {
                if alocuente[j] == 0 {
                    pos += 1
                    if pos == int(op[1]) {
                        alocuente[j-int(op[1])+1 : j+1] = make([]int, int(op[1]))
                        for k := j - int(op[1]) + 1; k <= j; k++ {
                            alocuente[k] = ind
                        }
                        fmt.Println(ind)
                        ind += 1
                        break
                    }
                } else {
                    pos = 0
                }
            }
            if pos!= int(op[1]) {
                fmt.Println("NULL")
            }
        }
        if op[0] == "erase" {
            pos := 0
            if int(op[1]) <= 0 || int(op[1]) > m || alocuente[int(op[1])-1] == 0 {
                fmt.Println("ILLEGAL_ERASE_ARGUMENT")
            } else {
                for j := 0; j < m; j++ {
                    if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
                        alocuente[j] = 0
                    }
                }
            }
        }
        if op[0] == "defragment" {
            cnt := 0
            cnt = len(alocuente) - count(alocuente, 0)
            alocuente = remove(alocuente, 0)
            for j := 0; j < cnt; j++ {
                alocuente = append(alocuente, 0)
            }
        }
    }
}

func count(s []int, e int) int {
    c := 0
    for _, v := range s {
        if v == e {
            c++
        }
    }
    return c
}

func remove(s []int, e int) []int {
    r := []int{}
    for _, v := range s {
        if v!= e {
            r = append(r, v)
        }
    }
    return r
}
