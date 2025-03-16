package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	n := 0
	var c byte
	var a, b int
	var MfriendPerDay [367]int
	var FfriendPerDay [367]int
	answer := 0

	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		c = scanner.Text()[0]
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a)
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &b)

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

