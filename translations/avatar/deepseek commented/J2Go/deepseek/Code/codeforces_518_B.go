package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	// Step 1: Read the input string `s` and the target string `t`.
	scanner.Scan()
	s := strings.Builder{}
	s.WriteString(scanner.Text())
	scanner.Scan()
	t := scanner.Text()
	
	// Initialize counters for the number of replacements
	var ura, opa int
	
	// Step 2: Create a frequency map `tmap` for characters in `t`.
	tmap := make(map[rune]int)
	for _, ch := range t {
		if _, ok := tmap[ch]; !ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}
	
	// Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
	length := len(s.String())
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		num, ok := tmap[ch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch]--
		}
		s.WriteString("Я")
		ura++
	}
	
	// Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		rch := reverse(ch)
		num, ok := tmap[rch]
		if !ok {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch]--
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

