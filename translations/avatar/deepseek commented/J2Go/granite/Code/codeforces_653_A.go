

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(reader.ReadLine())
    }
    sort.Ints(a)
    a = removeDuplicates(a)
    found := false
    for i := 0; i < len(a)-2; i++ {
        if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
            found = true
            break
        }
    }
    if found {
        fmt.Fprintln(writer, "YES")
    } else {
        fmt.Fprintln(writer, "NO")
    }
    writer.Flush()
}

func removeDuplicates(a []int) []int {
    result := make([]int, 0)
    for _, v := range a {
        if!contains(result, v) {
            result = append(result, v)
        }
    }
    return result
}

func contains(a []int, v int) bool {
    for _, x := range a {
        if x == v {
            return true
        }
    }
    return false
}

