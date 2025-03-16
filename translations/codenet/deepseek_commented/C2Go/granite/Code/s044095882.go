
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

	a := make([]int32, n)

	for i := 1; i < n; i++ {
		aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		a[i] = int32(aTemp)
	}

	count := make([]int32, n)

	for i := 1; i < n; i++ {
		count[a[i]-1]++
	}

	for i := 0; i < n; i++ {
		fmt.Println(count[i])
	}

	fmt.Println("