
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
	fmt.Scan(&t)
	var s []string
	pqmax := make([]int, 0)
	pqmin := make([]int, 0)
	var sumMin, sumMax, sumb int64
	var min int
	for t > 0 {
		s, _ = reader.ReadString('\n')
		s = strings.Split(s, " ")
		if s[0][0] == '2' {
			ans := int64(min)
			ans *= int64(len(pqmin))
			ans -= sumMin
			ans1 := int64(min)
			ans1 *= int64(len(pqmax))
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			in, _ := strconv.Atoi(s[1])
			sumb += int64(in2)
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += int64(in)
			} else {
				pqmin = append(pqmin, in)
				sumMin += int64(in)
			}
			if len(pqmin) > len(pqmax) {
				sumMax += int64(pqmin[0])
				sumMin -= int64(pqmin[0])
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}
			if len(pqmin) < len(pqmax) {
				sumMax -= int64(pqmax[0])
				sumMin += int64(pqmax[0])
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}
			min = pqmin[0]
		}
		t--
	}
}
