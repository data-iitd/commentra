package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter string s: ")
	s, _ := reader.ReadString('\n')
	fmt.Print("Enter string t: ")
	t, _ := reader.ReadString('\n')

	// Remove newline character from input strings
	s = strings.TrimSuffix(s, "\n")
	t = strings.TrimSuffix(t, "\n")

	// Initialize frequency maps
	freqs := make(map[rune]int)
	freqt := make(map[rune]int)

	// Populate frequency map for string s
	for _, letra := range s {
		freqs[letra]++
	}

	// Populate frequency map for string t
	for _, letra := range t {
		freqt[letra]++
	}

	// Initialize counters
	yay, whoops := 0, 0

	// Calculate yay
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay++
			freqs[letra]--
			freqt[letra]--
		}
	}

	// Calculate whoops
	for letra := range freqs {
		for freqs[letra] > 0 {
			if letra >= 'a' && letra <= 'z' && freqt[rune(letra-32)] > 0 {
				whoops++
				freqs[letra]--
				freqt[rune(letra-32)]--
			} else if letra >= 'A' && letra <= 'Z' && freqt[rune(letra+32)] > 0 {
				whoops++
				freqs[letra]--
				freqt[rune(letra+32)]--
			} else {
				break
			}
		}
	}

	// Print the results
	fmt.Println(yay, whoops)
}
