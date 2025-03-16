// We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
freqs := make (map[rune]int)
freqt := make (map[rune]int)

// We read the two strings s and t from the user input
s, t := readString ()

// We iterate through each character in the string s and update the frequency count in the freqs dictionary
for _, letra := range s {
    freqs [letra]++
}

// We iterate through each character in the string t and update the frequency count in the freqt dictionary
for _, letra := range t {
    freqt [letra]++
}

// We initialize two counters, yay and whoops, to zero
yay, whoops := 0, 0

// We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
for letra, _ := range freqs {
    for freqs [letra] > 0 && letra in freqt && freqt [letra] > 0 {
        yay++
        freqs [letra]--
        freqt [letra]--
    }
}

// We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
for letra, _ := range freqs {
    for freqs [letra] > 0 {
        if letra >= 'a' && letra <= 'z' {
            if letra + 'A' - 'a' in freqt && freqt [letra + 'A' - 'a'] > 0 {
                whoops++
                freqs [letra]--
                freqt [letra + 'A' - 'a']--
            } else if letra + 'a' - 'A' in freqt && freqt [letra + 'a' - 'A'] > 0 {
                whoops++
                freqs [letra]--
                freqt [letra + 'a' - 'A']--
            } else {
                break
            }
        } else if letra >= 'A' && letra <= 'Z' {
            if letra + 'a' - 'A' in freqt && freqt [letra + 'a' - 'A'] > 0 {
                whoops++
                freqs [letra]--
                freqt [letra + 'a' - 'A']--
            } else if letra + 'A' - 'a' in freqt && freqt [letra + 'A' - 'a'] > 0 {
                whoops++
                freqs [letra]--
                freqt [letra + 'A' - 'a']--
            } else {
                break
            }
        } else {
            break
        }
    }
}

// Finally, we print the values of yay and whoops
fmt.Println (yay, whoops)

