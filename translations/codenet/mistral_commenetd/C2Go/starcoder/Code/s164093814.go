
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const M = 1046527
const L = 14

var H [M][L]string

func getChar(ch byte) int {
<<<<<<< HEAD
	switch ch {
	case 'A':
		return 1
	case 'C':
		return 2
	case 'G':
		return 3
	case 'T':
=======
	if ch == 'A' {
		return 1
	} else if ch == 'C' {
		return 2
	} else if ch == 'G' {
		return 3
	} else if ch == 'T' {
>>>>>>> 98c87cb78a (data updated)
		return 4
	}
	return 0
}

func getKey(str string) int64 {
	sum := int64(0)
	p := int64(1)
<<<<<<< HEAD
	for _, ch := range str {
		sum += p * int64(getChar(ch))
=======
	for i := 0; i < len(str); i++ {
		sum += p * int64(getChar(str[i]))
>>>>>>> 98c87cb78a (data updated)
		p *= 5
	}
	return sum
}

func h1(key int64) int {
	return int(key % M)
}

func h2(key int64) int {
	return 1 + int(key % (M - 1))
}

func find(str string) bool {
	var i, hash, key int64
	key = getKey(str)
	i = 0
	for {
<<<<<<< HEAD
		hash = int64(h1(key) + i*h2(key)) % M
		if H[hash] == "" {
			return false
		}
		if H[hash] == str {
			return true
=======
		hash = int64(h1(key) + i*int64(h2(key))) % M
		if H[hash] == str {
			return true
		} else if len(H[hash]) == 0 {
			return false
>>>>>>> 98c87cb78a (data updated)
		}
		i++
	}
}

func insert(str string) {
	var i, hash, key int64
	key = getKey(str)
	i = 0
	for {
<<<<<<< HEAD
		hash = int64(h1(key) + i*h2(key)) % M
		if H[hash] == "" {
=======
		hash = int64(h1(key) + i*int64(h2(key))) % M
		if len(H[hash]) == 0 {
>>>>>>> 98c87cb78a (data updated)
			H[hash] = str
			return
		}
		i++
	}
}

func main() {
	var i, n int
	var str, com string
	for i = 0; i < M; i++ {
		H[i][0] = ""
	}
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s %s", &com, &str)
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

