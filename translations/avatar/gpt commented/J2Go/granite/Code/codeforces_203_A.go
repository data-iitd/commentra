
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
	var x, t, a, b, da, db int
	fmt.Fscanf(reader, "%d %d %d %d %d %d\n", &x, &t, &a, &b, &da, &db)
	for i := 0; i < t; i++ {
		for j := 0; j < t; j++ {
			if a-(i*da) == x || b-(j*db) == x || a-(i*da)+b-(j*db) == x || a == x || b == x || x == 0 {
				fmt.Println("YES")
				return
			}
		}
	}
	fmt.Println("NO")
}

