

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	M = 1046527
	L = 14
)

var H [M][L]string

func getChar(ch byte) int {
	switch ch {
	case 'A':
		return 1
	case 'C':
		return 2
	case 'G':
		return 3
	case 'T':
		return 4
	}
	return 0
}

func getKey(str string) int {
	sum := 0
	p := 1
	for _, ch := range str {
		sum += p * getChar(ch)
		p *= 5
	}
	return sum
}

func h1(key int) int {
	return key % M
}

func h2(key int) int {
	return 1 + (key % (M - 1))
}

func find(str string) bool {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == str {
			return true
		}
		if len(H[hash]) == 0 {
			return false
		}
		i++
	}
}

func insert(str string) {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if len(H[hash]) == 0 {
			H[hash] = str
			return
		}
		i++
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	for i := 0; i < n; i++ {
		fields := strings.Split(readLine(reader), " ")
		com, str := fields[0], fields[1]
		if com == "insert" {
			insert(str)
		} else {
			if find(str) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}

