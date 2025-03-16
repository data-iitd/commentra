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
	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var s string
		fmt.Fscan(reader, &s)
		if s[0] == '2' {
			var ans int
			ans = min
			ans *= len(pqmin)
			ans -= sumMin
			var ans1 int
			ans1 = min
			ans1 *= len(pqmax)
			ans1 = sumMax - ans1
			fmt.Println(min, " ", ans+ans1+sumb)
		} else {
			var in int
			var ans int
			fmt.Sscanf(s, "%d %d", &in, &ans)
			sumb += ans
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += in
			} else {
				pqmin = append(pqmin, in)
				sumMin += in
			}
			if len(pqmin) > len(pqmax) {
				sumMax += pqmin[0]
				sumMin -= pqmin[0]
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}
			if len(pqmin) < len(pqmax) {
				sumMax -= pqmax[0]
				sumMin += pqmax[0]
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}
			min = pqmin[0]
		}
	}
}

