<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	max := 0
	cnt := 0
	for _, sc := range str {
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			cnt++
		} else {
			cnt = 0
		}
		max = max < cnt {
			cnt
		}
	}
	fmt.Println(max)
}

