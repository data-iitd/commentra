package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod = 1000000007

// Function for base case
func mainB() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	pp := 0
	na := 0

	for i, c := range reverseString(s) {
		cc := na + int(c-'0')
		na = 0
		if cc <= 4 {
			pp += cc
		} else {
			na = 1
			if i == len(s)-1 {
				pp += 1
			}
			pp += 10 - cc
		}
	}
	fmt.Println(pp)
}

// Function for general case
func mainFunc() int {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	pmin := 1000
	mmin := 0
	s = "0" + s

	for _, c := range reverseString(s) {
		v := int(c - '0')
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin = npmin
		mmin = nmmin
	}
	return min(pmin, mmin)
}

// Helper function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	ret := mainFunc()
	if ret != 0 {
		fmt.Println(ret)
	}
}

// Note: The clipboard and file input methods are not implemented in this Go version.
// You can implement them based on your requirements.

