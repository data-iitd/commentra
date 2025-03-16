
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	FfriendPerDay := make([]int, 367)
	MfriendPerDay := make([]int, 367)
	answer := 0
	for i := 0; i < n; i++ {
		c, _ := reader.ReadLine()
		a, _ := strconv.Atoi(string(c[2]))
		b, _ := strconv.Atoi(string(c[4]))
		for j := a; j <= b; j++ {
			if c[0] == 'M' {
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
