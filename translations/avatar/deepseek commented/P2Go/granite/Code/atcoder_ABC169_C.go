

package main

import (
    "bufio"
    "bytes"
    "container/ring"
    "fmt"
    "io"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    var sa, sb string
    fmt.Fscan(reader, &sa, &sb)
    a, _ := strconv.Atoi(sa)
    b, _ := strconv.Atoi(strings.Replace(sb, ".", "", -1))
    fmt.Fprintln(writer, a*b/100)
    writer.Flush()
}

