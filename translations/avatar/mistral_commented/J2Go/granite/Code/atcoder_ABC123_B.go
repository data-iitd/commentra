
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
	var a []int
	var r []int
	var map = make(map[int]int)

	for i := 0; i < 5; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		num, _ := strconv.Atoi(input)
		a = append(a, num)
		r = append(r, num%10)

		if r[i]!= 0 {
			b := 10 - r[i]
			map[b] = a[i]
		}
	}

	var ans int
	if len(map) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	last := map[10]
	idx := 0
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
			break
		}
	}

	for i := 0; i < 5; i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}

	ans += last
	fmt.Println(ans)
}

