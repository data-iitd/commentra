package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var vec [100][4]int
	var ans int
	var ansprice int
	var fl int
	var i, j int
	var input *bufio.Reader
	var output *bufio.Writer
	input = bufio.NewReader(os.Stdin)
	output = bufio.NewWriter(os.Stdout)
	n, _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
	for i = 0; i < n; i++ {
		vec[i][0], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
		vec[i][1], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
		vec[i][2], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
		vec[i][3], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
	}
	ans = 500
	ansprice = 20000
	for i = 0; i < n; i++ {
		fl = 1
		for j = 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = 0
			}
		}
		if fl == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3]
				ans = i + 1
			}
		}
	}
	fmt.Println(ans)
	output.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

