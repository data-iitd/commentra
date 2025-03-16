
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    sec, _ := strconv.Atoi(read(reader))
    per_num, _ := strconv.Atoi(read(reader))
    max_sec, _ := strconv.Atoi(read(reader))

    ans_num := 0

    for i := sec; i < max_sec; i += sec {
        ans_num += per_num
    }

    fmt.Println(ans_num)
}

func read(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine()
    return string(str)
}

