package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    s, t := bufio.NewReader(os.Stdin).ReadString('\n')
    freqs := make(map[string]int)
    freqt := make(map[string]int)
    yay, whoops := 0, 0

    for _, letra := range s {
        letra = strings.TrimSpace(string(letra))
        if letra!= "" {
            if letra, ok := freqs[letra]; ok {
                freqs[letra] += 1
            } else {
                freqs[letra] = 1
            }
        }
    }

    for _, letra := range t {
        letra = strings.TrimSpace(string(letra))
        if letra!= "" {
            if letra, ok := freqt[letra]; ok {
                freqt[letra] += 1
            } else {
                freqt[letra] = 1
            }
        }
    }

    for letra, _ := range freqs {
        for freqs[letra] > 0 && letra!= "" && letra, ok := freqt[letra]; ok && freqt[letra] > 0 {
            yay += 1
            freqs[letra] -= 1
            freqt[letra] -= 1
        }
    }

    for letra, _ := range freqs {
        for freqs[letra] > 0 {
            if letra == strings.ToLower(letra) && strings.ToUpper(letra)!= "" && freqt[strings.ToUpper(letra)] > 0 {
                whoops += 1
                freqs[letra] -= 1
                freqt[strings.ToUpper(letra)] -= 1
            } else if letra == strings.ToUpper(letra) && strings.ToLower(letra)!= "" && freqt[strings.ToLower(letra)] > 0 {
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

