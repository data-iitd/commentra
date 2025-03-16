package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	strs := strings.Split(line, " ")
	nums := make([]int, len(strs))
	for i, str := range strs {
		num, _ := strconv.Atoi(str)
		nums[i] = num
	}
	return nums
}

func readFloats(reader *bufio.Reader) []float64 {
	line := readLine(reader)
	strs := strings.Split(line, " ")
	nums := make([]float64, len(strs))
	for i, str := range strs {
		num, _ := strconv.ParseFloat(str, 64)
		nums[i] = num
	}
	return nums
}

func readInt(reader *bufio.Reader) int {
	line := readLine(reader)
	num, _ := strconv.Atoi(line)
	return num
}

func readFloat(reader *bufio.Reader) float64 {
	line := readLine(reader)
	num, _ := strconv.ParseFloat(line, 64)
	return num
}

func readString(reader *bufio.Reader) string {
	line := readLine(reader)
	return line
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	s := readString(reader)
	k := readInt(reader)
	l := 0
	for _, c := range s {
		if string(c) != "1" {
			break
		}
		l++
	}
	if l >= k {
		fmt.Println(1)
		return
	}
	fmt.Println(string(s[l]))
}

