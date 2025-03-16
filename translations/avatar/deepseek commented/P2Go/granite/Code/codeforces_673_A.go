
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	arrTemp := strings.Split(readLine(reader), " ")

	var arr []int32

	for i := 0; i < int(n); i++ {
		arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		arr = append(arr, arrItem)
	}

	if arr[0] > 15 {
		fmt.Println(15)
	} else {
		for i := 1; i < len(arr); i++ {
			if arr[i]-arr[i-1] > 15 {
				fmt.Println(arr[i-1] + 15)
				break
			}
		}

		if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
			fmt.Println(90)
		} else {
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}

	fmt.Println("