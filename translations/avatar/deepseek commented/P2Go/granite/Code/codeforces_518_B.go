
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)

    t, _ := reader.ReadString('\n')
    t = strings.TrimSpace(t)

    freqs := make(map[string]int)
    freqt := make(map[string]int)

    yay := 0
    whoops := 0

    for _, letra := range s {
        freqs[string(letra)]++
    }

    for _, letra := range t {
        freqt[string(letra)]++
    }

    for letra, _ := range freqs {
        for freqs[letra] > 0 && freqt[letra] > 0 {
            yay++
            freqs[letra]--
            freqt[letra]--
        }
    }

    for letra, _ := range freqs {
        for freqs[letra] > 0 {
            if strings.ToLower(letra) == letra && freqt[strings.ToUpper(letra)] > 0 {
                whoops++
                freqs[letra]--
                freqt[strings.ToUpper(letra)]--
            } else if strings.ToUpper(letra) == letra && freqt[strings.ToLower(letra)] > 0 {
                whoops++
                freqs[letra]--
                freqt[strings.ToLower(letra)]--
            } else {
                break
            }
        }
    }

    fmt.Println(yay, whoops)
}
