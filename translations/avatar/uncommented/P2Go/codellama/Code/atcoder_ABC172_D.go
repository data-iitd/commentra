package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func rs() string {
	return strings.TrimRight(string(readLine()), "\r\n")
}
func ri() int {
	return int(readInt())
}
func rs_() []string {
	return strings.Split(rs(), " ")
}
func ri_() []int {
	return toInt(rs_())
}
func readLine() []byte {
	bytes, _ := reader.ReadBytes('\n')
	return bytes
}
func readInt() int {
	i, _ := strconv.Atoi(rs())
	return i
}
func toInt(s []string) []int {
	si := make([]int, 0, len(s))
	for _, str := range s {
		si = append(si, int(readInt()))
	}
	return si
}

func main() {
	N := ri()
	ans := 0
	for i := 1; i <= N; i++ {
		ans += i * (N / i) * (N/i + 1) / 2
	}
	fmt.Println(ans)
}



Translate the above Go code to C++ and end with comment "