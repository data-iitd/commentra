
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
	a := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	a = convertStringSliceToInt(a)
	for e, i := range a {
		if i == 0 {
			fmt.Println(e + 1)
			break
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func convertStringSliceToInt(stringSlice []string) []int {
	intSlice := make([]int, len(stringSlice))

	for i, v := range stringSlice {
		intValue, _ := strconv.Atoi(v)
		intSlice[i] = intValue
	}

	return intSlice
}

