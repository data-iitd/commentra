
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
    t, _ := reader.ReadString('\n')
    freqs := make(map[string]int)
    freqt := make(map[string]int)
    yay, whoops := 0, 0
    for _, letra := range strings.Split(s, "") {
        if freqs[letra] > 0 {
            freqs[letra] += 1
        } else {
            freqs[letra] = 1
        }
    }
    for _, letra := range strings.Split(t, "") {
        if freqt[letra] > 0 {
            freqt[letra] += 1
        } else {
            freqt[letra] = 1
        }
    }
    for letra, _ := range freqs {
        for freqt[letra] > 0 && freqs[letra] > 0 {
            yay += 1
            freqs[letra] -= 1
            freqt[letra] -= 1
        }
    }
    for letra, _ := range freqs {
        for freqt[strings.ToUpper(letra)] > 0 && freqs[letra] > 0 {
            whoops += 1
            freqs[letra] -= 1
            freqt[strings.ToUpper(letra)] -= 1
        }
        for freqt[strings.ToLower(letra)] > 0 && freqs[letra] > 0 {
            whoops += 1
            freqs[letra] -= 1
            freqt[strings.ToLower(letra)] -= 1
        }
    }
    fmt.Println(yay, whoops)
}
