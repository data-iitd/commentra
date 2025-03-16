<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	var com, str string
	var T map[string]bool

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	T = make(map[string]bool)
	for i := 0; i < n; i++ {
<<<<<<< HEAD
		fmt.Fscanf(reader, "%s%s", &com, &str)
=======
		fmt.Fscan(reader, &com, &str)
>>>>>>> 98c87cb78a (data updated)
		if com[0] == 'i' {
			T[str] = true
		} else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

