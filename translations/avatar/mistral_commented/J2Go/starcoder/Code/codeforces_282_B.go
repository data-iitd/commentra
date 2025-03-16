/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var x, y int
	var s1, s2 int
	var ch []string
	var ans string
	var flag int
	var i, j int
	var temp1, temp2 int
	var dif int

	sc := bufio.NewScanner(os.Stdin)
	n, _ = strconv.Atoi(sc.Text())

	ch = make([]string, n)
	for i = 0; i < n; i++ {
		x, _ = strconv.Atoi(sc.Text())
		y, _ = strconv.Atoi(sc.Text())

		temp1 = s1 + x
		temp2 = s2 + y

		if (temp1-temp2 <= 500) || (temp1-s2 <= 500) {
			s1 += x
			ch[j] = "A"
			j++
			continue
		}

		if (temp2-temp1 <= 500) || (s2-temp1 <= 500) {
			s2 += y
			ch[j] = "G"
			j++
			continue
		}

		flag = 1
		break
	}

	if flag == 1 {
		fmt.Println(-1)
	} else {
		ans = strings.Join(ch, "")
		fmt.Println(ans)
	}
}

