
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

func main() {
// Reading input from stdin
reader := bufio.NewReader(os.Stdin)

// Reading the number of test cases
var t, _ = strconv.Atoi(readLine(reader))

for t > 0 {
// Reading the value of n
var n, _ = strconv.Atoi(readLine(reader))

// Reading the value of a
var a, _ = strconv.Atoi(readLine(reader))

// Reading the value of b
var b, _ = strconv.Atoi(readLine(reader))

if n < a {
fmt.Println("No")
continue
}

if a == b {
if n%a == 0 {
fmt.Println("Yes")
} else {
fmt.Println("No")
}
continue
}

// Calculating the value of x
x := b / (b - a)

if n > x*a {
fmt.Println("Yes")
continue
}

// Initializing a long variable named low to 1
low := 1

// Initializing a long variable named high to x + 1
high := x + 1

// Initializing a long variable named ans to 1
ans := 1

for low <= high {
// Calculating the middle value of low and high
mid := (low + high) / 2

if mid*a < n {
low = mid + 1
} else {
ans = mid
high = mid - 1
}
}

if n > (ans-1)*b && n < ans*a {
fmt.Println("No")
} else {
fmt.Println("Yes")
}

t--
}
}

// Reading input from stdin
func readLine(reader *bufio.Reader) string {
str, _, err := reader.ReadLine()
if err == io.EOF {
return ""
}
return strings.TrimRight(string(str), "\r\n")
}

