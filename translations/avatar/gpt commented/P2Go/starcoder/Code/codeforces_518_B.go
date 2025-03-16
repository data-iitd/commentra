// Read two strings from input
s, t := bufio.NewReader(os.Stdin).ReadString('\n')

// Initialize dictionaries to store frequency counts of characters in both strings
freqs := make(map[rune]int)
freqt := make(map[rune]int)

// Initialize counters for matching characters
yay, whoops := 0, 0

// Count the frequency of each character in the first string's'
for _, letra := range s {
    freqs[letra]++
}

// Count the frequency of each character in the second string 't'
for _, letra := range t {
    freqt[letra]++
}

// Compare character frequencies from both strings to count exact matches
for letra, _ := range freqs {
    for freqs[letra] > 0 && letra <= utf8.MaxRune && letra in freqt && freqt[letra] > 0 {
        yay++
        freqs[letra]--
        freqt[letra]--
    }
}

// Compare remaining characters for case-insensitive matches
for letra, _ := range freqs {
    for freqs[letra] > 0 {
        // Check for a lowercase letter in's' and its uppercase counterpart in 't'
        if unicode.IsLower(letra) && unicode.ToUpper(letra) in freqt && freqt[unicode.ToUpper(letra)] > 0 {
            whoops++
            freqs[letra]--
            freqt[unicode.ToUpper(letra)]--
        }
        // Check for an uppercase letter in's' and its lowercase counterpart in 't'
        if unicode.IsUpper(letra) && unicode.ToLower(letra) in freqt && freqt[unicode.ToLower(letra)] > 0 {
            whoops++
            freqs[letra]--
            freqt[unicode.ToLower(letra)]--
        } else {
            break
        }
    }
}

// Print the results: number of exact matches and case-insensitive matches
fmt.Println(yay, whoops)

