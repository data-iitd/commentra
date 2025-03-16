
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

num, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

arr := make([]string, num)

for i := 0; i < num; i++ {
arr[i] = strings.TrimSpace(readLine(reader))
}

var fine int

for i := 0; i < num; i++ {
count := 0
for j := 0; j < num; j++ {
if string(arr[j][i]) == "C" {
count++
}
}
fine += (count * (count - 1)) / 2
}

for i := 0; i < num; i++ {
count := 0
for j := 0; j < num; j++ {
if string(arr[i][j]) == "C" {
count++
}
}
fine += (count * (count - 1)) / 2
}

fmt.Println(fine)
}

func readLine(reader *bufio.Reader) string {
str, _, err := reader.ReadLine()
if err == nil {
return strings.TrimRight(string(str), "\r\n")
}
return ""
}

