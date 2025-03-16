
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var n int
    fmt.Fscan(reader, &n)

    r := make([]int, n)
    for i := 0; i < n; i++ {
        s, _ := reader.ReadString('\n')
        r[i], _ = strconv.Atoi(s)
    }

    ans := int(math.Abs(float64(r[0])))
    for i := 1; i < n; i++ {
        ans += int(math.Abs(float64(r[i] - r[i-1])))
    }

    fmt.Println(ans)
}
