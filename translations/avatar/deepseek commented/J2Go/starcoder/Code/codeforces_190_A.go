
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
	fmt.Println("Enter the first integer")
	first, _ := reader.ReadString('\n')
	first = strings.Replace(first, "\n", "", -1)
	firstInt, _ := strconv.Atoi(first)
	fmt.Println("Enter the second integer")
	second, _ := reader.ReadString('\n')
	second = strings.Replace(second, "\n", "", -1)
	secondInt, _ := strconv.Atoi(second)

	if firstInt == 0 {
		if secondInt!= 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println(0, 0)
		}
		return
	}

	if secondInt <= firstInt {
		if secondInt == 0 {
			secondInt = 1
		}
		fmt.Println(firstInt, secondInt+firstInt-1)
		return
	}

	fmt.Println(secondInt, secondInt+firstInt-1)
}

