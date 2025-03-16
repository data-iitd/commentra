package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter first string: ")
	s, _ := reader.ReadString('\n')
	fmt.Print("Enter second string: ")
	t, _ := reader.ReadString('\n')

	freqs := make(map[rune]int)
	freqt := make(map[rune]int)
	var yay, whoops int

	// Populating the frequency dictionaries
	for _, letra := range s {
		if _, ok := freqs[letra]; ok {
			freqs[letra] += 1
		} else {
			freqs[letra] = 1
		}
	}

	for _, letra := range t {
		if _, ok := freqt[letra]; ok {
			freqt[letra] += 1
		} else {
			freqt[letra] = 1
		}
	}

	// Counting yay by matching characters in freqs and freqt
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay += 1
			freqs[letra] -= 1
			freqt[letra] -= 1
		}
	}

	// Counting whoops by transforming characters to match
	for letra := range freqs {
		for freqs[letra] > 0 {
			if letra >= 'a' && letra <= 'z' && letra-32 <= 'Z' && freqt[letra-32] > 0 {
				whoops += 1
				freqs[letra] -= 1
				freqt[letra-32] -= 1
			} else if letra >= 'A' && letra <= 'Z' && letra+32 <= 'z' && freqt[letra+32] > 0 {
				whoops += 1
				freqs[letra] -= 1
				freqt[letra+32] -= 1
			} else {
				break
			}
		}
	}

	fmt.Println(yay, whoops)
}
