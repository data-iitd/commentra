
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
    var n, k int
    var cards [26]c462b
    var ans int64

    reader := bufio.NewReader(os.Stdin)
    fmt.Fscan(reader, &n, &k)

    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]

    for i := 0; i < n; i++ {
        cards[s[i]-'A'].left++
    }

    for i := 0; i < k; i++ {
        sort.Slice(cards, func(i, j int) bool {
            return cards[i].left > cards[j].left
        })
        change := int(min(cards[25].left, int64(k-i)))
        ans += int64(change) * int64(change)
        cards[25].left -= change
        i += change - 1
    }

    fmt.Println(ans)
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

type c462b struct {
    left int
}

