
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	tmap := make(map[string]int)
	for _, ch := range t {
		if _, ok := tmap[string(ch)]; !ok {
			tmap[string(ch)] = 1
		} else {
			tmap[string(ch)]++
		}
	}
	ura := 0
	opa := 0
	for i, ch := range s {
		if num, ok := tmap[string(ch)]; ok {
			if num == 1 {
				delete(tmap, string(ch))
			} else {
				tmap[string(ch)]--
			}
			ura++
			s = s[:i] + "Я" + s[i+1:]
		}
	}
	for i, ch := range s {
		if num, ok := tmap[string(reverse(ch))]; ok {
			if num == 1 {
				delete(tmap, string(reverse(ch)))
			} else {
				tmap[string(reverse(ch))]--
			}
			opa++
		}
	}
	fmt.Println(ura, opa)
}

func reverse(ch string) string {
	if strings.ToLower(ch) == ch {
		return strings.ToUpper(ch)
	} else {
		return strings.ToLower(ch)
	}
}

