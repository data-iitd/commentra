package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	freqs := make(map[rune]int)
	freqt := make(map[rune]int)
	yay, whoops := 0, 0

	for _, letra := range s {
		if _, ok := freqs[letra]; ok {
			freqs[letra]++
		} else {
			freqs[letra] = 1
		}
	}
	for _, letra := range t {
		if _, ok := freqt[letra]; ok {
			freqt[letra]++
		} else {
			freqt[letra] = 1
		}
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

	fmt.Println(yay, whoops)
}

