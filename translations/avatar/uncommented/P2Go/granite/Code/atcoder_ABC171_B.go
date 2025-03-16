
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	arrTemp := strings.Split(readLine(reader), " ")
	var arr []int
	for i := 0; i < n; i++ {
		arrItem, _ := strconv.Atoi(arrTemp[i])
		arr = append(arr, arrItem)
	}
	result := solve(n, k, arr)
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

func solve(n int, k int, arr []int) int32 {
	// Write your code here that takes n, k and arr as input and returns an integer.
	return 0
}

