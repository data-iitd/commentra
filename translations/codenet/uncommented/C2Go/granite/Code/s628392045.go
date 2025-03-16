
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

	hTemp := strings.Split(readLine(reader), " ")

	var h []int32

	for i := 0; i < int(n); i++ {
		hItemTemp, err := strconv.ParseInt(hTemp[i], 10, 64)
		checkError(err)
		hItem := int32(hItemTemp)
		h = append(h, hItem)
	}

	result := jumpingOnClouds(n, h)

	fmt.Println(result)
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

func jumpingOnClouds(n int32, h []int32) string {
	max := int32(0)
	for i := 0; i < int(n); i++ {
		if h[i] > max {
			max = h[i]
		}
	}

	for i := 0; i < int(n); i++ {
		if h[i] == max {
			if i+2 < int(n) && h[i+2] == 0 {
				return "No"
			}
		}
	}

	return "Yes"
}

