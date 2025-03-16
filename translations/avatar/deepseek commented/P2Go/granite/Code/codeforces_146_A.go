
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

	numberTemp := readLine(reader)
	var number string
	for numberTemp!= "" {
		number += numberTemp
		numberTemp = readLine(reader)
	}

	h1 := int32(0)
	h2 := int32(0)
	x := int32(0)

	for i := int32(0); i < n; i++ {
		if number[i]!= '4' && number[i]!= '7' {
			fmt.Println("NO")
			x = 1
			break
		}
		if i < n/2 {
			h1 += int32(number[i] - '0')
		} else {
			h2 += int32(number[i] - '0')
		}
	}

	if x == 0 {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}
