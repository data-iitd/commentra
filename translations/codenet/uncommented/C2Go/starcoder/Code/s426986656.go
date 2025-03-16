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
	fmt.Println("Enter two numbers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	nums := strings.Split(input, ",")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	flag := false
	for i := 1; i <= 3; i++ {
		if (a*b*i)%2 == 1 {
			flag = true
			break
		}
	}
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

