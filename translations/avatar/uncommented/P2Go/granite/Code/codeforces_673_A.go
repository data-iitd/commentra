
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
	fmt.Print("Enter the number of elements: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0 : len(reader.ReadLine())-1])
	fmt.Print("Enter the elements separated by space: ")
	input := reader.ReadLine()[0 : len(reader.ReadLine())-1]
	arr := strings.Split(input, " ")
	var result int
	if arr[0]!= "0" {
		result, _ = strconv.Atoi(arr[0])
		if result > 15 {
			fmt.Println(15)
		} else {
			for i := 1; i < len(arr); i++ {
				result, _ = strconv.Atoi(arr[i])
				if result-strconv.Atoi(arr[i-1]) > 15 {
					fmt.Println(strconv.Atoi(arr[i-1]) + 15)
					break
				}
			}
			if result+15 >= 90 {
				fmt.Println(90)
			} else {
				fmt.Println(result + 15)
			}
		}
	} else {
		fmt.Println(15)
	}
}
