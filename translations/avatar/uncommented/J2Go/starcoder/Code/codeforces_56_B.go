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
	fmt.Println("Enter the length of the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	length, _ := strconv.Atoi(input)
	array := make([]int, length)
	fmt.Println("Enter the array elements")
	for i := 0; i < length; i++ {
		fmt.Println("Enter the element", i+1)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		array[i], _ = strconv.Atoi(input)
	}
	l := 0
	r := 0
	flag := false
	isTrue := false
	for i := 0; i < length; i++ {
		if array[i]!= i+1 &&!flag {
			l = i + 1
			flag = true
			continue
		}
		if array[i]!= i+1 && flag {
			r = i + 1
			if (array[r-1]-array[r-2] > 0) {
				isTrue = true
				break
			}
		}
	}
	if!isTrue {
		fmt.Println(l, " ", r)
	} else {
		fmt.Println("0 ", "0")
	}
}

