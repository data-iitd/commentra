package main

import (
"fmt"
"math"
"os"
"strconv"
"strings"
)

func main() {
var a, t, h, lt, lh, tt, hh, l int
var taro, hana string
fmt.Scanf("%d", &a)
for i := 0; i < a; i++ {
fmt.Scanf("%s %s", &taro, &hana)
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
fmt.Printf("%d %d\n", t, h)
}

