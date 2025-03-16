
package main

import (
"fmt"
"math"
)

func main() {

var n int
var a []int
var b []int
var temp int
var q int
var w int
var e int
var f bool

fmt.Scan(&n)
a = make([]int, n)
b = make([]int, n)
temp = math.MinInt32
q = math.MinInt32
w = math.MinInt32
e = math.MinInt32
f = false

for i := 0; i < n; i++ {
fmt.Scan(&a[i])
fmt.Scan(&b[i])

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

