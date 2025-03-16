
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	t := int32(tTemp)

	for tGrader := int32(0); tGrader < t; tGrader++ {
		s := readLine(reader)

		res := make([]string, 0)

		for i := 1; i < len(s); i++ {
			prefix := s[:i]
			suffix := s[i:]

			res = append(res, prefix+suffix)
			res = append(res, suffix+prefix)

			revPrefix := reverse(prefix)
			res = append(res, revPrefix+suffix)
			res = append(res, suffix+revPrefix)

			revSuffix := reverse(suffix)
			res = append(res, prefix+revSuffix)
			res = append(res, revSuffix+prefix)

			res = append(res, prefix+revSuffix)
			res = append(res, revSuffix+prefix)
		}

		sort.Strings(res)
		unique := 0
		for i := 0; i < len(res)-1; i++ {
			if res[i]!= res[i+1] {
				unique++
			}
		}
		unique++

		fmt.Println(unique)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

