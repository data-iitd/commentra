

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
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
    a := make([]int, n+1)
    b := make([]int, n+1)
    num := make([]int, n+1)
    st := make([]bool, n+1)
    for i := 1; i <= n; i ++ {
        s := strings.Split(reader.ReadLine(), " ")
        a[i], _ = strconv.Atoi(s[0])
        b[i], _ = strconv.Atoi(s[1])
    }
    ss := ""
    ans := 0
    for i := 1; i <= n; i ++ {
        if a[i] == 1 {
            st[i] = true
            sb := strings.Builder{}
            x := b[i]
            sss := strings.Builder{}
            sss.WriteString(strconv.Itoa(i))
            sb.WriteString(" " + sss.String())
            s := 1
            for st[x] == false && num[x] == 1 && x!= 0 && a[x]!= 1 {
                sss := strings.Builder{}
                sss.WriteString(strconv.Itoa(x))
                sb.WriteString(" " + sss.String())
                st[x] = true
                x = b[x]
                s ++
            }
            if s > ans {
                ans = s
                ss = sb.String()
            }
        }
    }
    fmt.Println(ans)
    fmt.Println(ss)
}

