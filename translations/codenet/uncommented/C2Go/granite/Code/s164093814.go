
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

var H [M][L]byte

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

func getKey(str string) int64 {
	sum := int64(0)
	p := int64(1)
	for _, ch := range str {
		sum += p * int64(getChar(ch))
		p *= 5
	}
	return sum
}

func h1(key int64) int {
	return int(key % M)
}

func h2(key int64) int {
	return 1 + int(key%(M-1))
}

func find(str string) bool {
	i, hash, key := 0, 0, getKey(str)
	for {
		hash = (h1(key) + i*h2(key)) % M
		if H[hash][0] == 0 {
			return false
		}
		if H[hash] == str {
			return true
		}
		i++
	}
}

func insert(str string) bool {
	i, hash, key := 0, 0, getKey(str)
	for {
		hash = (h1(key) + i*h2(key)) % M
		if H[hash][0] == 0 {
			H[hash] = []byte(str)
			return false
		}
		if H[hash] == str {
			return true
		}
		i++
	}
}

func main() {
	var n int
	var str, com string
	var err error
	var buf [L]byte
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		}
	}
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			com = scanner.Text()
		}
		if scanner.Scan() {
			copy(buf[:], scanner.Bytes())
			str = string(buf[:strings.IndexByte(buf[:],'')])
		}
		if com[0] == 'i' {
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

