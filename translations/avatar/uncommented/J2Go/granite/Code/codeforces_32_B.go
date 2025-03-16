
package main

import (
"bufio"
"fmt"
"os"
"strings"
)

func main() {
in := bufio.NewReader(os.Stdin)
s, _ := in.ReadString('\n')
s = strings.TrimSpace(s)
s = strings.Replace(s, ".", "", -1)

s = strings.Replace(s, "00", "2", -1)
s = strings.Replace(s, "11", "2", -1)

s = strings.Replace(s, "0", "1", -1)
s = strings.Replace(s, "1", "0", -1)

fmt.Println(s)
}

