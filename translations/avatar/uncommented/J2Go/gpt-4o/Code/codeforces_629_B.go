package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	FfriendPerDay := make([]int, 367)
	MfriendPerDay := make([]int, 367)
	answer := 0

	for i := 0; i < n; i++ {
		var c byte
		var a, b int
		fmt.Scanf(" %c %d %d", &c, &a, &b)

		for j := a; j <= b; j++ {
			if c == 'M' {
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

// <END-OF-CODE>
