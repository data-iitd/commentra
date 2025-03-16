

package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    s := readString()
    s = strings.ReplaceAll(s, "BC", "D")
    cnt := int64(0)
    tmp := int64(0)
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            tmp++
        } else if s[i] == 'D' {
            cnt += tmp
        } else {
            tmp = 0
        }
    }
    fmt.Println(cnt)
}

func readString() string {
    s, _ := in.ReadString('\n')
    return strings.TrimSpace(s)
}
// The Go code reads the input string, replaces all occurrences of "BC" with "D", and counts the number of occurrences of "AD" in the modified string. The result is printed to the standard output.