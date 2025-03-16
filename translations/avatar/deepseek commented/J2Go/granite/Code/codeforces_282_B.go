
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
	s1 := int32(0)
	s2 := int32(0)
	flag := false
	var dif int32
	var ch []rune
	j := int32(0)
	for i := int32(0); i < n; i++ {
		xTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		x := int32(xTemp)
		yTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		y := int32(yTemp)
		temp1 := s1 + x
		temp2 := s2 + y
		if int32(math.Abs(float64(temp1-s2))) <= 500 {
			s1 += x
			ch = append(ch, 'A')
			continue
		}
		if int32(math.Abs(float64(temp2-s1))) <= 500 {
			s2 += y
			ch = append(ch, 'G')
			continue
		}
		flag = true
		break
	}
	if flag {
		fmt.Println(-1)
	} else {
		fmt.Println(string(ch))
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

