<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(reader, &n)
	a, b, c := make([]byte, n), make([]byte, n), make([]byte, n)
	fmt.Fscan(reader, &a, &b, &c)
	ans := 0
	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Println(ans)
}

