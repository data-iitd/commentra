

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

	aTemp := strings.Split(readLine(reader), " ")

	var a []int32

	for i := 0; i < int(n); i++ {
		aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
		checkError(err)
		aItem := int32(aItemTemp)
		a = append(a, aItem)
	}

	leftl := make([]int32, n)
	rightl := make([]int32, n)

	que := make([]int32, 0)

	index := int32(0)

	for index < n {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			rightl[ind] = index - ind - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index++
	}

	for len(que) > 0 {
		ind := que[len(que)-1]
		rightl[ind] = n - ind - 1
		que = que[:len(que)-1]
	}

	index = int32(n - 1)

	for index >= 0 {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			leftl[ind] = ind - index - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index--
	}

	for len(que) > 0 {
		ind := que[len(que)-1]
		leftl[ind] = ind - index - 1
		que = que[:len(que)-1]
	}

	var ans int64 = 0

	for i := int32(0); i < n; i++ {
		ans += int64(a[i]) * (int64(leftl[i]) + 1) * (int64(rightl[i]) + 1)
	}

	fmt.Println(ans)
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