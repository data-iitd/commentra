package main

import (
	"fmt"
	"strconv"
)

func main() {
	var str string

	for {
		fmt.Scan(&str)
		if str == "0" {
			break
		}
		sum := 0
		for i := 0; i < len(str); i++ {
			tmp := string(str[i])
			num, _ := strconv.Atoi(tmp)
			sum += num
		}
		fmt.Println(sum)
	}
}

// <END-OF-CODE>
