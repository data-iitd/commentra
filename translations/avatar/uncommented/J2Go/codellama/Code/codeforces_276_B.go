
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var str string
	fmt.Scanln(&str)
	var map = make(map[string]int)
	var oddCount int
	for i := 0; i < len(str); i++ {
		if _, ok := map[string(str[i])]; ok {
			map[string(str[i])]++
		} else {
			map[string(str[i])] = 1
		}
	}
	for _, v := range map {
		if v%2 != 0 {
			oddCount++
		}
	}
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}

