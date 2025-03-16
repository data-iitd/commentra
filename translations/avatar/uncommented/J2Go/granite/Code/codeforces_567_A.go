
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
s := bufio.NewScanner(os.Stdin)
s.Split(bufio.ScanWords)

var a int
s.Scan()
a, _ = strconv.Atoi(s.Text())

ar := make([]int, a)

for i := 0; i < a; i++ {
s.Scan()
ar[i], _ = strconv.Atoi(s.Text())
}

max := 0
min := 0

for i := 0; i < a; i++ {
if i == 0 {
min = ar[i+1] - ar[i]
} else if i == a-1 {
min = ar[i] - ar[i-1]
} else {
min = int(math.Min(float64(ar[i]-ar[i-1]), float64(ar[i+1]-ar[i])))
}

if i == 0 {
max = ar[a-1] - ar[i]
} else {
max = int(math.Max(float64(ar[i]-ar[0]), float64(ar[a-1]-ar[i])))
}

fmt.Println(min, max)
}
}
