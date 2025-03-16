
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
	tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	t := int32(tTemp)
	arrTemp := strings.Split(readLine(reader), " ")
	var arr []int32
	for i := 0; i < int(t); i++ {
		arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		arr = append(arr, arrItem)
	}
	prevWinner := int32(0)
	for i := 0; i < int(t); i++ {
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
		}
		if prevWinner == 2 || prevWinner == 0 {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2)
				prevWinner = 2
			} else {
				fmt.Println(1)
				prevWinner = 1
			}
		} else {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1)
				prevWinner = 1
			} else {
				fmt.Println(2)
				prevWinner = 2
			}
		}
	}
	fmt.Println("