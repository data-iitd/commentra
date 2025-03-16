

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

	mTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	m := int32(mTemp)

	qTemp := strings.Split(readLine(reader), " ")

	var q []int32

	for i := 0; i < int(m); i++ {
		qItemTemp, err := strconv.ParseInt(qTemp[i], 10, 64)
		checkError(err)
		qItem := int32(qItemTemp)
		q = append(q, qItem)
	}

	for q_itr := 0; q_itr < int(m); q_itr++ {
		result := fun(arr, q[q_itr], n, m)
		fmt.Println(result + 1)
	}
}

func fun(arr []int32, q int32, n int32, m int32) int32 {
	res := int32(0)
	i := int32(0)
	j := n - 1

	for i <= j {
		md := i + (j-i)/2

		if arr[md] == q {
			return md
		} else if arr[md] > q {
			res = md
			j = md - 1
		} else {
			i = md + 1
		}
	}

	return res
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

