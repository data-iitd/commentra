
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s := strings.Builder{}
	fmt.Fscan(reader, &s)
	t := ""
	fmt.Fscan(reader, &t)
	ura := 0
	opa := 0
	tmap := make(map[rune]int)
	for _, ch := range t {
		if _, ok := tmap[ch];!ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}
	length := s.Len()
	for i := 0; i < length; i++ {
		ch := s.String()[i]
		num, ok := tmap[ch]
		if!ok {
			continue
		}
		if num == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch]--
		}
		s.SetChar(i, 'Я')
		ura++
	}
	for i := 0; i < length; i++ {
		ch := s.String()[i]
		rch := reverse(ch)
		num, ok := tmap[rch]
		if!ok {
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
	if unicode.IsLower(ch) {
		return unicode.ToUpper(ch)
	} else {
		return unicode.ToLower(ch)
	}
}

