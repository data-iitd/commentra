
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var number int64
	fmt.Scan(&number)
	var ans int64 = -1
	var value int64 = 0
	var mask int = 2
	for value < number {
		s := strconv.FormatInt(int64(mask), 2)
		s = s[1:]
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}
		if zeros != len(s)-zeros {
			mask++
			continue
		}
		s = s[:zeros] + "4" + s[zeros:]
		s = s[:zeros] + "7" + s[zeros:]
		value, _ = strconv.ParseInt(s, 2, 64)
		mask++
	}
	fmt.Println(value)
}

