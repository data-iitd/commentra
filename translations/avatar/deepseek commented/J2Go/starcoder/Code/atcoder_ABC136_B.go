
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var count int
	var temp int
	var ans int

	stdIn := bufio.NewReader(os.Stdin)
	fmt.Fscan(stdIn, &N)
	count = 0
	temp = N
	ans = 0

	for temp > 0 {
		temp /= 10
		count++
	}

	for i := 1; i <= count; i++ {
		if i == count {
			if i%2 == 1 {
				ans += (N - int(math.Pow(10, float64(i-1))) + 1)
			}
		} else {
			if i == 1 {
				ans += 9
			} else if i%2 == 1 {
				ans += (int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1))))
			}
		}
	}

	fmt.Println(ans)
}

