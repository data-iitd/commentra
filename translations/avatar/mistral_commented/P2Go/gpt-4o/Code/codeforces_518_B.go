package main

import (
	"fmt"
	"strings"
)

func main() {
	// We start by defining two empty maps to store the frequency of each character in the strings s and t respectively
	freqs := make(map[rune]int)
	freqt := make(map[rune]int)

	// We read the two strings s and t from the user input
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	// We iterate through each character in the string s and update the frequency count in the freqs map
	for _, letra := range s {
		freqs[letra]++
	}

	// We iterate through each character in the string t and update the frequency count in the freqt map
	for _, letra := range t {
		freqt[letra]++
	}

	// We initialize two counters, yay and whoops, to zero
	yay, whoops := 0, 0

	// We iterate through each character in the freqs map and check if its frequency is greater than zero
	for letra, count := range freqs {
		for count > 0 && freqt[letra] > 0 {
			yay++
			freqs[letra]--
			freqt[letra]--
			count--
		}
	}

	// We iterate through each character in the freqs map again
	for letra, count := range freqs {
		for count > 0 {
			if unicode.IsLower(letra) && freqt[unicode.ToUpper(letra)] > 0 {
				whoops++
				freqs[letra]--
				freqt[unicode.ToUpper(letra)]--
				count--
			} else if unicode.IsUpper(letra) && freqt[unicode.ToLower(letra)] > 0 {
				whoops++
				freqs[letra]--
				freqt[unicode.ToLower(letra)]--
				count--
			} else {
				break
			}
		}
	}

	// Finally, we print the values of yay and whoops
	fmt.Println(yay, whoops)
}

// <END-OF-CODE>
