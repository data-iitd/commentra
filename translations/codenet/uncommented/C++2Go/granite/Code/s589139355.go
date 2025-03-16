
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
var a int
var t int = 0
var h int = 0
var lt int
var lh int
var tt int
var hh int
var l int
var taro string
var hana string

fmt.Scanln(&a)
for i := 0; i < a; i++ {
fmt.Scanln(&taro, &hana)
lt = len(taro)
lh = len(hana)
if lt > lh {
l = lt
} else {
l = lh
}
tt = 0
hh = 0

if taro > hana {
t = t + 3
} else if hana > taro {
h = h + 3
} else if hana == taro {
h = h + 1
t = t + 1
}
}
fmt.Println(t, h)
}

