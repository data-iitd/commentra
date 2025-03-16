
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	FfriendPerDay := make([]int, 367)
	MfriendPerDay := make([]int, 367)
	answer := 0
	for i := 0; i < n; i++ {
		sc.Scan()
		c := sc.Text()
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		for j := a; j <= b; j++ {
			if c == "M" {
				MfriendPerDay[j]++
			} else {
				FfriendPerDay[j]++
			}
			if MfriendPerDay[j] < FfriendPerDay[j] {
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j]
				}
			} else {
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j]
				}
			}
		}
	}
	fmt.Println(answer * 2)
}

