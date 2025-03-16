

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
    writer := bufio.NewWriter(os.Stdout)

    n, _ := strconv.Atoi(reader.ReadLine()[2:])

    cnt := make([]int, 5)
    for i := 0; i < n; i++ {
        str := reader.ReadLine()
        switch str[0] {
        case 'M':
            cnt[0]++
        case 'A':
            cnt[1]++
        case 'R':
            cnt[2]++
        case 'C':
            cnt[3]++
        case 'H':
            cnt[4]++
        }
    }

    res := int64(0)
    for i := 0; i < 5; i++ {
        for j := i + 1; j < 5; j++ {
            for k := j + 1; k < 5; k++ {
                res += int64(cnt[i]) * int64(cnt[j]) * int64(cnt[k])
            }
        }
    }

    fmt.Fprintln(writer, res)
    writer.Flush()
}

// Translate the above Go code to C++ and end with comment "