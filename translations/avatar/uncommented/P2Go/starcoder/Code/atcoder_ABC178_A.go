package main
import (
"fmt"
"os"
"bufio"
)
func main() {
reader := bufio.NewReader(os.Stdin)
tc := 1
for tc > 0 {
tc--
a, _ := reader.ReadString('\n')
a = a[:len(a)-1]
a = int(a)
fmt.Println(1)
}
}
