package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	freqs := make(map[rune]int)
	freqt := make(map[rune]int)
	yay, whoops := 0, 0

	for _, letra := range s {
		freqs[letra]++
	}

	for _, letra := range t {
		freqt[letra]++
	}

	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay++
			freqs[letra]--
			freqt[letra]--
		}
	}

	for letra := range freqs {
		for freqs[letra] > 0 {
			if unicode.IsLower(letra) && freqt[unicode.ToUpper(letra)] > 0 {
				whoops++
				freqs[letra]--
				freqt[unicode.ToUpper(letra)]--
			} else if unicode.IsUpper(letra) && freqt[unicode.ToLower(letra)] > 0 {
				whoops++
				freqs[letra]--
				freqt[unicode.ToLower(letra)]--
			} else {
				break
			}
		}
	}

	fmt.Println(yay, whoops)
}

// <END-OF-CODE>
