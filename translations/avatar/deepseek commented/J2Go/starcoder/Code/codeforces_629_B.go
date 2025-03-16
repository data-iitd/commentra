
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
	fmt.Println("Enter the number of entries: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the entries: ")
	MfriendPerDay := make([]int, 367)
	FfriendPerDay := make([]int, 367)
	answer := 0
	for i := 0; i < n; i++ {
		s := strings.Split(strings.TrimSpace(reader.ReadString()), " ")
		c := s[0]
		a, _ := strconv.Atoi(s[1])
		b, _ := strconv.Atoi(s[2])
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

