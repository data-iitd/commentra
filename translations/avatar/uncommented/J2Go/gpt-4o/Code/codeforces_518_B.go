package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	var t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	ura := 0
	opa := 0
	tmap := make(map[rune]int)

	for _, ch := range t {
		tmap[ch]++
	}

	length := len(s)
	sBuilder := strings.Builder{}

	for i, ch := range s {
		num, exists := tmap[ch]
		if !exists {
			sBuilder.WriteRune(ch)
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch]--
		}
		sBuilder.WriteRune('Я')
		ura++
	}

	s = sBuilder.String()

	for _, ch := range s {
		rch := reverse(ch)
		num, exists := tmap[rch]
		if !exists {
			continue
		}
		if num == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch]--
		}
		opa++
	}

	fmt.Println(ura, opa)
}

func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 'a' + 'A'
	} else if ch >= 'A' && ch <= 'Z' {
		return ch - 'A' + 'a'
	}
	return ch
}

// <END-OF-CODE>
