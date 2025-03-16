
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
    freqs := make (map [string]int)
    freqt := make (map [string]int)

    // We read the two strings s and t from the user input
    reader := bufio.NewReader (os.Stdin)
    fmt.Print ("Enter the first string: ")
    s, _ := reader.ReadString ('\n')
    fmt.Print ("Enter the second string: ")
    t, _ := reader.ReadString ('\n')

    // We iterate through each character in the string s and update the frequency count in the freqs dictionary
    for _, letra := range strings.Split (s, "") {
        freqs [letra] += 1
    }

    // We iterate through each character in the string t and update the frequency count in the freqt dictionary
    for _, letra := range strings.Split (t, "") {
        freqt [letra] += 1
    }

    // We initialize two counters, yay and whoops, to zero
    yay, whoops := 0, 0

    // We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
    for letra, _ := range freqs {
        for freqs [letra] > 0 && freqt [letra] > 0 {
            yay += 1
            freqs [letra] -= 1
            freqt [letra] -= 1
        }
    }

    // We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
    for letra, _ := range freqs {
        for freqs [letra] > 0 {
            if strings.ToLower (letra) == letra && freqt [strings.ToUpper (letra)] > 0 {
                whoops += 1
                freqs [letra] -= 1
                freqt [strings.ToUpper (letra)] -= 1
            } else if strings.ToUpper (letra) == letra && freqt [strings.ToLower (letra)] > 0 {
                whoops += 1
                freqs [letra] -= 1
                freqt [strings.ToLower (letra)] -= 1
            } else {
                break ;
            }
        }
    }

    // Finally, we print the values of yay and whoops
    fmt.Println (yay, whoops)
}
