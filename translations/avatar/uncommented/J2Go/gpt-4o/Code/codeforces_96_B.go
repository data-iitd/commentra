package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var number int64
	fmt.Scan(&number)
	var ans int64 = -1
	var value int64 = 0
	mask := 2

	for value < number {
		s := strconv.FormatInt(int64(mask), 2)[1:] // Convert mask to binary and skip the first character
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
		s = strings.ReplaceAll(s, "0", "4")
		s = strings.ReplaceAll(s, "1", "7")
		value, _ = strconv.ParseInt(s, 10, 64)
		mask++
	}
	fmt.Println(value)
}

// <END-OF-CODE>
