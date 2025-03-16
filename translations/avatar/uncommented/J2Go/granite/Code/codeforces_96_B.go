
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
	number, _ := reader.ReadString('\n')
	number = strings.TrimSpace(number)
	ans, value := int64(-1), int64(0)
	mask := 2
	for value < int64(number) {
		s := fmt.Sprintf("%b", mask)
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
		value, _ = strconv.ParseInt(s, 10, 64)
		mask++
	}
	fmt.Println(value)
}

