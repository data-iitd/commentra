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
	input, _ := reader.ReadString('\n')
	inputs := strings.Split(strings.TrimSpace(input), " ")
	N, _ := strconv.Atoi(inputs[0])
	K, _ := strconv.Atoi(inputs[1])
	
	input, _ = reader.ReadString('\n')
	S := strings.TrimSpace(input)
	
	aaaa := false
	
	if K >= 15 {
		aaaa = true
	} else if 1<<K >= N {
		aaaa = true
	}
	
	if aaaa {
		fmt.Println(strings.Repeat(string(S[0]), N))
		return
	}
	
	type Result struct {
		U string
		MinIndex int
	}
	
	getLastDict := func(s string) Result {
		U := s + s[len(s)-1::-1]
		c := minChar(s)
		p := strings.Index(U, string(c))
		minIndex := p
		p++
		for p <= len(U) {
			if U[p] == c && checkNormalDict(U, minIndex, p) {
				minIndex = p
			}
			p++
		}
		return Result{U[minIndex:minIndex+len(s)], minIndex}
	}
	
	checkNormalDict := func(u string, pointer1, pointer2 int) bool {
		for i := 0; i < len(u); i++ {
			if u[pointer1+i] > u[pointer2+i] {
				return true
			} else if u[pointer1+i] < u[pointer2+i] {
				return false
			}
		}
		return false
	}
	
	result := getLastDict(S)
	S = result.U
	
	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		for _, c := range S {
			if c == rune(S[0]) {
				count++
			} else {
				break
			}
		}
		if count * (1 << (K - 1)) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), count * (1 << (K - 1)) - 1) + S
			fmt.Println(S[:N])
		}
	}
}

func minChar(s string) byte {
	minChar := s[0]
	for i := 1; i < len(s); i++ {
		if s[i] < minChar {
			minChar = s[i]
		}
	}
	return minChar
}

