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
	var k int
	var a [100100]int
	var min, max int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &k)

	for i := 0; i < k; i++ {
<<<<<<< HEAD
		fmt.Fscan(reader, &a[i])
=======
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
>>>>>>> 98c87cb78a (data updated)
	}

	max = 3
	min = 2

	if a[k-1]!= 2 {
		fmt.Println(-1)
		return
	}

	for i := k - 2; i >= 0; i-- {
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1
			if min%a[i]!= 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		if max <= min {
			fmt.Println(-1)
			return
		}
	}

	fmt.Printf("%d %d\n", min, max)
}

