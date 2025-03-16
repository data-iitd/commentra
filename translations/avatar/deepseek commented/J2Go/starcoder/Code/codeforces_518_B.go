
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 1: Read the input string `s` and the target string `t`.
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	s = bufio.NewScanner(strings.NewReader(s.Text()))
	s.Scan()
	t := s.Text()

	// Initialize counters for the number of replacements
	ura := 0 // Counter for replacements in step 3
	opa := 0 // Counter for replacements in step 4

	// Step 2: Create a frequency map `tmap` for characters in `t`.
	tmap := make(map[rune]int)
	for _, ch := range t {
		if _, ok := tmap[ch];!ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}

	// Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
	for i, ch := range s.Text() {
		if _, ok := tmap[ch];!ok {
			continue
		}
		num := tmap[ch]
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = num - 1
		}
		s.Text()[i] = 'Я'
		ura++
	}

	// Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
	for i, ch := range s.Text() {
		rch := reverse(ch)
		if _, ok := tmap[rch];!ok {
			continue
		}
		num := tmap[rch]
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
	} else if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}

