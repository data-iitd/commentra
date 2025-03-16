
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(nTemp, 10, 64)
	checkError(err)

	kTemp, err := reader.ReadString('\n')
	checkError(err)
	k, err := strconv.ParseInt(kTemp, 10, 64)
	checkError(err)

	qTemp, err := reader.ReadString('\n')
	checkError(err)
	q, err := strconv.ParseInt(qTemp, 10, 64)
	checkError(err)

	arr := make([]int, int(n))
	for i := 0; i < int(n); i++ {
		arr[i] = 0
	}

	for i := 0; i < int(q); i++ {
		tempTemp, err := reader.ReadString('\n')
		checkError(err)
		temp, err := strconv.ParseInt(tempTemp, 10, 64)
		checkError(err)
		arr[int(temp)-1] += 1
	}

	for i := 0; i < int(n); i++ {
		if int64(arr[i]) > q-k {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

