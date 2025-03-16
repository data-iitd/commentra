
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
var scList []string

scan := bufio.NewScanner(os.Stdin)
for scan.Scan() {
scList = append(scList, scan.Text())
}

numlist := strings.Split(scList[0], " ")
Sheep, _ := strconv.Atoi(numlist[0])
Wolve, _ := strconv.Atoi(numlist[1])

if Wolve >= Sheep {
fmt.Println("unsafe")
} else {
fmt.Println("safe")
}
}

