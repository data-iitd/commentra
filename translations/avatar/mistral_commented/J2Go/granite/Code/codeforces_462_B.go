

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

    var n, k int
    fmt.Fscanf(reader, "%d %d\n", &n, &k)

    cards := make([]int, 26)
    s, _ := reader.ReadString('\n')
    for _, c := range s[:n] {
        cards[c-'A']++
    }

    ans := 0
    for i := 0; i < k; i++ {
        maxIndex := 0
        for j := 1; j < 26; j++ {
            if cards[j] > cards[maxIndex] {
                maxIndex = j
            }
        }
        change := cards[maxIndex] - i
        if change <= 0 {
            break
        }
        ans += change * change
        cards[maxIndex] -= change
        i += change - 1
    }

    fmt.Fprintln(writer, ans)
    writer.Flush()
}

Translate the above Go code to C++ and end with comment "