package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var n int
var cake [ ] string
var happiness int
var chocCount int
var nfat int
var i int
var j int
var line string
fmt.Scanf("%d\n", &n)
for i = 0; i < n; i++ {
line, _ = bufio.NewReader(os.Stdin).ReadString('\n')
cake = strings.Split(line, "")
for j = 0; j < len(cake); j++ {
if cake[j] == "C" {
chocCount++
}
}
if chocCount > 1 {
for i = chocCount; i > chocCount-2; i-- {
nfat *= i
}
happiness += nfat / 2
}
nfat = 1
chocCount = 0
}
posCount := 0
for j = 0; j < n; j++ {
for i = 0; i < n; i++ {
if cake[i][j] == "C" {
chocCount++
}
}
if chocCount > 1 {
for i = chocCount; i > chocCount-2; i-- {
nfat *= i
}
happiness += nfat / 2
}
nfat = 1
chocCount = 0
}
fmt.Printf("%d\n", happiness)
}
