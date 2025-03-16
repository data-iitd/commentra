

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	firstlineTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	firstline := int32(firstlineTemp)

	total := int32(0)
	memory := []string{}

	for x := int32(0); x < firstline; x++ {
		AGTemp := strings.Split(readLine(reader), " ")

		var A int32
		var G int32
		A, err = strconv.ParseInt(AGTemp[0], 10, 64)
		checkError(err)
		G, err = strconv.ParseInt(AGTemp[1], 10, 64)
		checkError(err)

		if total+A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}

	fmt.Println(strings.Join(memory, ""))
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
