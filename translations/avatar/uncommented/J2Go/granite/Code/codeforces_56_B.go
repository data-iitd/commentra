
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
	fmt.Println("Enter the length of the array:")
	len, _ := reader.ReadString('\n')
	len = strings.TrimSpace(len)
	length, _ := strconv.Atoi(len)
	array := make([]int, length)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < length; i++ {
		element, _ := reader.ReadString('\n')
		element = strings.TrimSpace(element)
		array[i], _ = strconv.Atoi(element)
	}
	l := 0
	r := 0
	flag := false
	isTrue := false
loop:
	for i := 0; i < length; i++ {
		if array[i]!= i+1 &&!flag {
			l = i + 1
			flag = true
			continue
		}
		if array[i]!= i+1 && flag {
			r = i + 1
			if array[r-1]-array[r-2] > 0 {
				isTrue = true
				break loop
			}
		}
	}
	if!isTrue {
		fmt.Println(l, r)
	} else {
		fmt.Println(0, 0)
	}
}

