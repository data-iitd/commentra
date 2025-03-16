package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var h1, m1, h2, m2 int
fmt.Sscanf(os.Args[1], "%d:%d", &h1, &m1)
m1 += h1 * 60
fmt.Sscanf(os.Args[2], "%d:%d", &h2, &m2)
m2 += h2 * 60
m2 = m1 - m2
m2 %= 1440
fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}
