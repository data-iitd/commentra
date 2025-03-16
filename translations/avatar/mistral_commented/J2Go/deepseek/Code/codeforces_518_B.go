package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := strings.Builder{}
	s.WriteString(scanner.Text())
	scanner.Scan()
	t := scanner.Text()

	// Initialize counters for unique characters in the first string and opposite characters in the second string
	ura := 0
	opa := 0

	// Create a map to store the frequency of each character in the second string
	tmap := make(map[rune]int)

	// Read the characters of the second string and store their frequencies in the map
	for _, ch := range t {
		if _, ok := tmap[ch]; !ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}

	// Process the first string
	length := len(s.String())
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		num, _ := tmap[ch]
		if num == 0 {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch]--
		}
		s.Replace(string(ch), "Я", 1)
		ura++
	}

	// Process the reversed version of the first string
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		rch := reverse(ch)
		num, _ := tmap[rch]
		if num == 0 {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch]--
		}
		opa++
	}

	// Print the results
	fmt.Println(ura, opa)
}

// Reverse the given character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 32
	} else if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}

