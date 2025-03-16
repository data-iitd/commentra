
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
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.ParseInt(strings.TrimSpace(text), 10, 64)

	ans := int64(-1)
	value := int64(0)
	mask := 2

	for value < number {
		s := fmt.Sprintf("%b", mask)
		s = s[1:]
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}
		if zeros!= len(s)-zeros {
			mask++
			continue
		}
		s = strings.Replace(s, "0", "4", -1)
		s = strings.Replace(s, "1", "7", -1)
		value, _ = strconv.ParseInt(s, 2, 64)
		mask++
	}

	fmt.Println(value)
}

