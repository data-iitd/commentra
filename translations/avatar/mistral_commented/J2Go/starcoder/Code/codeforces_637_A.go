
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
// Reading input from stdin
reader := bufio.NewReader(os.Stdin)

// Reading the number of elements in the array
n, _ := strconv.Atoi(reader.ReadString('\n'))

// Creating an integer array of size n
ara := make([]int, n)

// Creating an empty HashMap to store the frequency of each integer
var map map[int]int
map = make(map[int]int)

// Reading elements of the array and updating the frequency in the HashMap
for i := 0; i < n; i++ {
v, _ := strconv.Atoi(reader.ReadString('\n'))
ara[i] = v
if _, ok := map[v];!ok {
map[v] = 1
} else {
map[v] = map[v] + 1
}
}

// Finding the maximum frequency in the HashMap
max := 0
for _, i := range map {
max = int(math.Max(float64(max), float64(i)))
}

// Finding the element(s) with the maximum frequency
var mm map[int]int
mm = make(map[int]int)
for i := 0; i < n; i++ {
if _, ok := mm[ara[i]];!ok {
mm[ara[i]] = 1
if mm[ara[i]] == max {
fmt.Println(ara[i])
break
}
} else {
mm[ara[i]] = mm[ara[i]] + 1
if mm[ara[i]] == max {
fmt.Println(ara[i])
break
}
}
}
}

