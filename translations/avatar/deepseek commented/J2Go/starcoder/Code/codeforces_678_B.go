
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
	year, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	leap := check_leap(year)
	sum := 0
	mod := 0

	for i := year + 1; ; i++ {
		if check_leap(i) {
			sum += 366
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if (check_leap(i) && leap) || (!check_leap(i) &&!leap) {
				fmt.Println(i)
				return
			} else {
				continue
			}
		}
	}
}

func check_leap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100!= 0)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

