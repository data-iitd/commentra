
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var str_v []string
    var maxsize int
    var maxcnt int
    var ans_num int
    var ans_num2 int

    for {
        in, _, err := reader.ReadLine()
        if err!= nil {
            break
        }
        str_v = append(str_v, string(in))
        if maxsize < len(in) {
            maxsize = len(in)
            ans_num = len(str_v) - 1
        }
    }

    for i := 0; i < len(str_v); i++ {
        cnt := 0
        for j := 0; j < len(str_v); j++ {
            if str_v[i] == str_v[j] {
                cnt++
            }
        }
        if maxcnt < cnt {
            maxcnt = cnt
            ans_num2 = i
        }
    }

    fmt.Println(str_v[ans_num2], str_v[ans_num])
}

