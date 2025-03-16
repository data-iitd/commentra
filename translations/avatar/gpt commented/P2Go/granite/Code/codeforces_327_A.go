
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

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	s := readLine(reader)

	s = strings.Replace(s, "", "", -1)

	zeroes := strings.Count(s, "0")

	if zeroes == 0 {
		fmt.Println(n - 1)
	} else if zeroes == 1 {
		fmt.Println(n)
	} else {
		max := 0
		for i := 0; i < len(s); i++ {
			if s[i] == '0' {
				for j := i + 1; j < len(s); j++ {
					if s[j] == '0' {
						dist := j - i
						max = int(math.Max(float64(max), float64(2+2*(dist-1)-(dist-1))))
					}
				}
			}
		}

		fmt.Println(strings.Count(s, "1") + max)
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

