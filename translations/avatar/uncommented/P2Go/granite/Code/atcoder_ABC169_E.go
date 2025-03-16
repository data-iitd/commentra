
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func resolve() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLineString()))
    low := make([]int, n)
    high := make([]int, n)
    for i := 0; i < n; i++ {
        a, b := strings.Split(strings.TrimSpace(reader.ReadLineString()), " ")
        low[i], _ = strconv.Atoi(a)
        high[i], _ = strconv.Atoi(b)
    }
    sort.Ints(low)
    sort.Ints(high)
    if n%2 == 1 {
        fmt.Println(high[(n+1)/2-1]-low[(n+1)/2-1]+1)
    } else {
        hh := (high[n/2-1] + high[n/2]) / 2
        ll := (low[n/2-1] + low[n/2]) / 2
        fmt.Println(int((float64(hh-ll)*2))+1)
    }
}

func main() {
    resolve()
}

