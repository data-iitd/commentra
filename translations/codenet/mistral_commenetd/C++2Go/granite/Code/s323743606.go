

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)

    m := make(map[int]int)

    for i := 0; i*200 < 5001; i++ {
        for j := 0; j*300 < 5001; j++ {
            for k := 0; k*500 < 5001; k++ {
                w := i*200 + j*300 + k*500
                p := i/5*5*380*80/100 + i%5*380 +
                    j/4*4*550*85/100 + j%4*550 +
                    k/3*3*850*88/100 + k%3*850
                if v, ok := m[w]; ok {
                    if p < v {
                        m[w] = p
                    }
                } else {
                    m[w] = p
                }
            }
        }
    }

    for scanner.Scan() {
        if n, err := strconv.Atoi(scanner.Text()); err == nil {
            fmt.Println(m[n])
        }
    }
    if err := scanner.Err(); err!= nil {
        fmt.Fprintln(os.Stderr, "reading standard input:", err)
    }
}

