
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b, c int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d %d\n", &a, &b, &c)
	if b <= c {
		fmt.Println("NO")
		return
	} else {
		d := a
		e := d % b
		for i := 0; i < b; i++ {
			d = d % b
			if d == c {
				fmt.Println("YES")
				return
			} else if i!= 0 && d == c {
				fmt.Println("NO")
				return
			}
			d += a
		}
	}
	fmt.Println("NO")
}

