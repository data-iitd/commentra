
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
	var n, k, t, i, p, ret int
	var data [111111]int
	var seq [222222]int
	var max func(int, int) int
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	max = func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Fscanf(reader, "%d %d\n", &n, &k)
		if n == 0 && k == 0 {
			break
		}
		for i := 0; i < k; i++ {
			fmt.Fscanf(reader, "%d\n", &t)
			data[t]++
		}
		p = 0
		for i := 1; i <= n; i++ {
			if data[i]!= 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++
		if data[0]!= 0 {
			for i := 0; i < p; i += 2 {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i += 2 {
				ret = max(ret, seq[i])
			}
		}
		fmt.Printf("%d\n", ret)
	}
}

