
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
var x, y, a, b int64
var j int64 = 2
var x1, y1, c int64
var ans bool = true

scanner := bufio.NewScanner(os.Stdin)
if scanner.Scan() {
x, _ = strconv.ParseInt(scanner.Text(), 10, 64)
}
if scanner.Scan() {
y, _ = strconv.ParseInt(scanner.Text(), 10, 64)
}
if scanner.Scan() {
a, _ = strconv.ParseInt(scanner.Text(), 10, 64)
}
if scanner.Scan() {
b, _ = strconv.ParseInt(scanner.Text(), 10, 64)
}

c = int64(math.Max(float64(x), float64(y)))
if c > b {
fmt.Println("0")
ans = false
}

for c%int64(math.Min(float64(x), float64(y)))!= 0 && ans {
if x > y {
c = x * j
j++
} else {
c = y * j
j++
}
if c > b {
fmt.Println("0")
ans = false
break
}
}

if ans {
i := a
for i = a; i <= b; i++ {
if i%c == 0 {
break
}
}
if i!= b+1 {
fmt.Println(((b - i) / c) + 1)
} else {
fmt.Println("0")
}
}
}
