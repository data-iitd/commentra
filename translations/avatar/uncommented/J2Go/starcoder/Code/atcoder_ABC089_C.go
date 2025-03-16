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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(reader, &n)
		cnt := make([]int, 5)
		for j := 0; j < n; j++ {
			s := strings.Split(strings.TrimSpace(readLine(reader)), " ")
			if s[0] == "M" {
				cnt[0]++
			} else if s[0] == "A" {
				cnt[1]++
			} else if s[0] == "R" {
				cnt[2]++
			} else if s[0] == "C" {
				cnt[3]++
			} else if s[0] == "H" {
				cnt[4]++
			}
		}
		res := cnt[0]*cnt[1]*cnt[2] + cnt[0]*cnt[1]*cnt[3] + cnt[0]*cnt[1]*cnt[4] + cnt[0]*cnt[2]*cnt[3] + cnt[0]*cnt[2]*cnt[4] + cnt[0]*cnt[3]*cnt[4] + cnt[1]*cnt[2]*cnt[3] + cnt[1]*cnt[2]*cnt[4] + cnt[1]*cnt[3]*cnt[4] + cnt[2]*cnt[3]*cnt[4]
		fmt.Fprintln(writer, res)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

