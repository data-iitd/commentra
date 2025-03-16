
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

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

	ans := make([]int32, n)

	mx := arr[n-1]

	for i := n - 2; i >= 0; i-- {
		ans[i] = int32(max(0, int(mx-arr[i]+1)))

		if arr[i] > mx {
			mx = arr[i]
		}
	}

	fmt.Println(strings.Trim(fmt.Sprint(ans), "[]"))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

