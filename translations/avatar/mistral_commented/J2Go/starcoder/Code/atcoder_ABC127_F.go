
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	var t int
	var s []string
	var pqmax, pqmin []int
	var sumMin, sumMax, sumb int
	var min int

	reader := bufio.NewReader(os.Stdin)
	t, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	for t > 0 {
		s = strings.Split(strings.TrimSpace(reader.ReadString()), " ")
		if s[0][0] == '2' {
			ans := min
			ans *= len(pqmin)
			ans -= sumMin
			ans1 := min
			ans1 = sumMax - ans1
			fmt.Println(min, " ", ans+ans1+sumb)
		} else {
			in, _ := strconv.Atoi(s[1])
			sumb += int(strings.TrimSpace(s[2]))

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
			} else if len(pqmin) < len(pqmax) {
				sumMax -= pqmax[0]
				sumMin += pqmax[0]
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}

			min = pqmin[0]
		}
		t--
	}
}

// 