

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	y, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))

	leap := check_leap(y)

	sum := 0
	mod := 0

	for i := y + 1; ; i++ {
		if check_leap(i) {
			sum += 366
			if (leap && check_leap(i)) || (!leap &&!check_leap(i)) {
				fmt.Fprintln(out, i)
				break
			}
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if (leap && check_leap(i)) || (!leap &&!check_leap(i)) {
				continue
			}
			fmt.Fprintln(out, i)
			break
		}
	}

	out.Flush()
}

func readLine(in *bufio.Reader) string {
	str, _, err := in.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func check_leap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100!= 0)
}

