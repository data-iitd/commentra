
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
	ab := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	aTemp, err := strconv.ParseInt(ab[0], 10, 64)
	checkError(err)
	a := int32(aTemp)
	bTemp, err := strconv.ParseInt(ab[1], 10, 64)
	checkError(err)
	b := int32(bTemp)
	bStr := fmt.Sprintf("%d", b)
	num := a * int32(math.Pow(10, float64(len(bStr)))) + b
	i := int32(1)
	for i = 1; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}
	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
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
