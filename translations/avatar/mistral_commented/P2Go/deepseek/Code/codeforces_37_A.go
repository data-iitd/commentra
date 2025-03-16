package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, _ := strconv.Atoi(readLine(reader))
	l := make([]int, n)

	input, _ := reader.ReadString('\n')
	nums := bufio.NewScanner(strings.NewReader(input))
	nums.Split(bufio.ScanWords)

	i := 0
	for nums.Scan() {
		l[i], _ = strconv.Atoi(nums.Text())
		i++
	}

	high := 1
	maximum := n
	tower := n

	for i := 1; i < n; i++ {
		if l[i] == l[i-1] {
			tower--
			high++
		} else {
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}

	if high > maximum {
		maximum = high
	}

	fmt.Fprintln(writer, maximum, tower)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}
