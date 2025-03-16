
package main

import "fmt"

func main() {
	s, t := input()
	freqs := make(map[string]int)
	freqt := make(map[string]int)
	yay, whoops := 0, 0
	for _, letra := range s {
		if _, ok := freqs[string(letra)]; ok {
			freqs[string(letra)] += 1
		} else {
			freqs[string(letra)] = 1
		}
	}
	for _, letra := range t {
		if _, ok := freqt[string(letra)]; ok {
			freqt[string(letra)] += 1
		} else {
			freqt[string(letra)] = 1
		}
	}
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay += 1
			freqs[letra] -= 1
			freqt[letra] -= 1
		}
	}
	for letra := range freqs {
		for freqs[letra] > 0 {
			if letra == strings.ToLower(letra) && strings.ToUpper(letra) == strings.ToUpper(letra) && freqt[strings.ToUpper(letra)] > 0 {
				whoops += 1
				freqs[letra] -= 1
				freqt[strings.ToUpper(letra)] -= 1
			} else if letra == strings.ToUpper(letra) && strings.ToLower(letra) == strings.ToLower(letra) && freqt[strings.ToLower(letra)] > 0 {
				whoops += 1
				freqs[letra] -= 1
				freqt[strings.ToLower(letra)] -= 1
			} else {
				break
			}
		}
	}
	fmt.Println(yay, whoops)
}

func input() (string, string) {
	var s, t string
	fmt.Scan(&s, &t)
	return s, t
}

