package main
import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

// Function to check the minimum possible value
func check(k int) int {
ans := 1000000000
for j := 0; j <= k; j++ {
if j > len(lst_p) || k-j > len(lst_m) {
continue
}
if j == 0 {
p := 0
} else {
p := lst_p[j-1]
}
if k-j == 0 {
m := 0
} else {
m := lst_m[len(lst_m)-(k-j)]
}
ans = min(ans, 2*p+abs(m), p+2*abs(m))
}
return ans
}

func main() {
// Reading input from stdin
reader := bufio.NewReader(os.Stdin)
fmt.Fscanln(reader, &N, &K)
lst := strings.Split(strings.TrimSpace(readLine(reader)), " ")
for i := 0; i < N; i++ {
num, _ := strconv.Atoi(lst[i])
lst[i] = num
}

// Separating positive and negative numbers
for i := 0; i < N; i++ {
if lst[i] == 0 {
K--
}
if lst[i] > 0 {
lst_p = append(lst_p, lst[i])
} else {
lst_m = append(lst_m, lst[i])
}
}

// Initialization of pointers and variables
p := 0
m := 0
x := 0
y := len(lst_m) - 1
lastx := len(lst_p)
lasty := len(lst_m)

// Output the result of the check function with K as the argument
fmt.Println(check(K))
}

func min(a, b, c int) int {
if a < b {
if a < c {
return a
}
return c
}
if b < c {
return b
}
return c
}

func readLine(reader *bufio.Reader) string {
str, _, err := reader.ReadLine()
if err == io.EOF {
return ""
}
return strings.TrimRight(string(str), "\r\n")
}

