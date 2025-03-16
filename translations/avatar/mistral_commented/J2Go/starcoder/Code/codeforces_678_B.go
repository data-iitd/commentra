
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
	leap := checkLeap(year)
	sum := 0
	mod := 0
	for i := year + 1; ; i++ {
		if checkLeap(i) {
			if leap && checkLeap(i) ||!leap &&!checkLeap(i) {
				fmt.Println(i)
				return
			}
			sum += 366
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if leap && checkLeap(i) ||!leap &&!checkLeap(i) {
				continue
			}
			fmt.Println(i)
			return
		}
	}
}

func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100!= 0)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

