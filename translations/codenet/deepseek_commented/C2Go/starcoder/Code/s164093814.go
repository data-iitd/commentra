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
	if ch == 'A' {
		return 1
	} else if ch == 'C' {
		return 2
	} else if ch == 'G' {
		return 3
	} else if ch == 'T' {
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

func h1(key int) int {
	return key % M
}

func h2(key int) int {
	return 1 + (key % (M - 1))
}

func find(str string) bool {
	i := 0
	key := getKey(str)
	for {
		hash := h1(key) + i*h2(key)
		if H[hash] == str {
			return true
		} else if len(H[hash]) == 0 {
			return false
		}
		i++
	}
}

func insert(str string) bool {
	i := 0
	key := getKey(str)
	for {
		hash := h1(key) + i*h2(key)
		if H[hash] == str {
			return true
		} else if len(H[hash]) == 0 {
			H[hash] = str
			return false
		}
		i++
	}
}

func main() {
	var n int
	var str, com string
	for i := 0; i < M; i++ {
		H[i][0] = ""
	}
<<<<<<< HEAD
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s %s", &com, &str)
=======

	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%s %s", &com, &str)

>>>>>>> 98c87cb78a (data updated)
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

