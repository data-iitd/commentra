
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
var n int
var a [1000000]int
var b [1000000]int
var temp int
var q int
var w int
var e int
var f bool

scanner := bufio.NewScanner(os.Stdin)
scanner.Scan()
n, _ = strconv.Atoi(scanner.Text())

for i := 0; i < n; i++ {
scanner.Scan()
a[i], _ = strconv.Atoi(scanner.Text())
scanner.Scan()
b[i], _ = strconv.Atoi(scanner.Text())

if temp < a[i] {
if q > b[i] {
f = true
}
q = b[i]
temp = a[i]
}

if temp > a[i] {
if q < b[i] {
f = true
}
q = b[i]
temp = a[i]
}

if a[i] > w {
w = a[i]
if b[i] < e {
f = true
}
}

if a[i] < w {
if b[i] > e {
f = true
}
}
}

if f == true {
fmt.Println("Happy Alex")
} else {
fmt.Println("Poor Alex")
}
}

