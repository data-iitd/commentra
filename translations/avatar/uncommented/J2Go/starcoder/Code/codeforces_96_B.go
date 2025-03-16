package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var number int64
	fmt.Scanf("%d", &number)
	ans := int64(-1)
	value := int64(0)
	mask := 2
	for value < number {
		s := strconv.FormatInt(mask, 2)
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}
		if zeros!= len(s)-zeros {
			continue
		}
		s = strings.Replace(s, "0", "4", -1)
		s = strings.Replace(s, "1", "7", -1)
		value, _ = strconv.ParseInt(s, 2, 64)
		mask++
	}
	fmt.Println(value)
}

