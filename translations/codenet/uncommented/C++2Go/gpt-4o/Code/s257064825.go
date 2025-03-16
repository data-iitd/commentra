package main

import (
	"fmt"
)

func main() {
	var str string
	fmt.Scan(&str)
	sum := int64(0)

	for _, x := range str {
		sum += int64(x - '0')
	}

	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
