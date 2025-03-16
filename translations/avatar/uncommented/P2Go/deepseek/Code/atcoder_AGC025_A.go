package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n string
	fmt.Scan(&n)
	a := []string{"10", "100", "1000", "10000", "100000"}
	
	sum := 0
	for _, char := range n {
		num, _ := strconv.Atoi(string(char))
		sum += num
	}
	
	found := false
	for _, val := range a {
		if n == val {
			found = true
			break
		}
	}
	
	if found {
		fmt.Println(10)
	} else {
		fmt.Println(sum)
	}
}

