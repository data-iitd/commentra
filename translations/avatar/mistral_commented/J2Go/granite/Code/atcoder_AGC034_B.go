

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    s := strings.Replace(reader.Text(), "BC", "D", -1)

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

    writer.Flush()
}

This Go code is equivalent to the Java code provided. It reads input from the console, replaces all occurrences of "BC" with "D" in the input string, and then counts the number of "D"s in the modified string. The result is then printed to the console.

Please note that the input is read from the console using the bufio package, and the output is written to the console using the bufio package as well.

Let me know if you need any further assistance or clarification.