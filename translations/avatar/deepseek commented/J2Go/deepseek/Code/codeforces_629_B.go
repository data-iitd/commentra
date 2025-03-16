package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())
	FfriendPerDay := make([]int, 367)
	MfriendPerDay := make([]int, 367)
	answer := 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		c := scanner.Text()[0]
		scanner.Scan()
		a := parseInt(scanner.Text())
		scanner.Scan()
		b := parseInt(scanner.Text())

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

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

