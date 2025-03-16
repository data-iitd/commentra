
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var l, r, d int64
	fmt.Fscanf(reader, "%d\n", &l)
	fmt.Fscanf(reader, "%d\n", &r)
	fmt.Fscanf(reader, "%d\n", &d)
	ans := int64(0)
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

// END-OF-CODE