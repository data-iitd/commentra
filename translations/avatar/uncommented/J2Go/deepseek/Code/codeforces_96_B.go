package main

import (
	"fmt"
	"strconv"
)

func main() {
	var number int64
	fmt.Scan(&number)
	ans := -1
	value := 0
	mask := 2
	for value < int(number) {
		s := strconv.FormatInt(int64(mask), 2)[1:]
		mask++
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}
		if zeros != len(s)-zeros {
			continue
		}
		s = strings.ReplaceAll(s, "0", "4")
		s = strings.ReplaceAll(s, "1", "7")
		value, _ = strconv.ParseInt(s, 10, 64)
	}
	fmt.Println(value)
}
