package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)
	if n != 1 {
		return
	}

	ac_count := 0
	wa_count := 0
	tle_count := 0
	re_count := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		if strings.EqualFold(s, "AC") {
			ac_count++
		} else if strings.EqualFold(s, "WA") {
			wa_count++
		} else if strings.EqualFold(s, "TLE") {
			tle_count++
		} else if strings.EqualFold(s, "RE") {
			re_count++
		}
	}
	fmt.Printf("AC x %d\n", ac_count)
	fmt.Printf("WA x %d\n", wa_count)
	fmt.Printf("TLE x %d\n", tle_count)
	fmt.Printf("RE x %d\n", re_count)
}

