
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 1: Read the input string `s` and the target string `t`.
	s := readLine()
	t := readLine()

	// Initialize counters for the number of replacements
	ura := 0 // Counter for replacements in step 3
	opa := 0 // Counter for replacements in step 4

	// Step 2: Create a frequency map `tmap` for characters in `t`.
	tmap := make(map[rune]int)
	for _, ch := range t {
		tmap[ch]++
	}

	// Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
	length := len(s)
	for i := 0; i < length; i++ {
		ch := s[i]
		num, ok := tmap[ch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = num - 1
		}
		s = s[:i] + "Я" + s[i+1:]
		ura++
	}

	// Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
	for i := 0; i < length; i++ {
		ch := s[i]
		rch := reverse(ch)
		num, ok := tmap[rch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch] = num - 1
		}
		opa++
	}

	// Step 5: Print the results `ura` and `opa`.
	fmt.Println(ura, opa)
}

// Helper method to reverse the case of a character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 32
	} else {
		return ch + 32
	}
}

// Helper method to read a line of input
func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// 