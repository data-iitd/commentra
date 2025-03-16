package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
func main() {
	reader := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscanln(reader, &t)
	for i := 0; i < t; i++ {
		var k, n, m int
		fmt.Fscanln(reader, &k, &n, &m)
		if k*m >= n {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
