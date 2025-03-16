
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Create a new Scanner object to read input from the console
    scan := bufio.NewScanner(os.Stdin)
    // Create a new StringBuilder object to store the first input string
    s := strings.Builder{}
    // Read the first input string from the console
    scan.Scan()
    s.WriteString(scan.Text())
    // Read the second input string from the console
    scan.Scan()
    t := scan.Text()

    // Initialize counters for unique characters in the first string and opposite characters in the second string
    ura := 0
    opa := 0

    // Create a HashMap to store the frequency of each character in the second string
    tmap := make(map[rune]int)

    // Read the characters of the second string and store their frequencies in the HashMap
    for _, ch := range t {
        if _, ok := tmap[ch]; !ok { // If the character is not already in the HashMap
            tmap[ch] = 1 // Add it with a frequency of 1
        } else {
            tmap[ch]++ // If the character is already in the HashMap, increment its frequency
        }
    }

    // Process the first string
    length := len(s.String())
    for i := 0; i < length; i++ {
        ch := rune(s.String()[i])
        num, ok := tmap[ch]
        if !ok { // If the character is not in the second string
            continue
        }
        inum := num
        if inum == 1 { // If the character appears only once in the second string
            delete(tmap, ch) // Remove it from the HashMap
        } else {
            tmap[ch] = inum - 1 // If the character appears more than once in the second string, decrement its frequency
        }
        s.WriteByte('Я') // Replace the character in the StringBuilder with 'Я'
        ura++ // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for i := 0; i < length; i++ {
        ch := rune(s.String()[i])
        rch := reverse(ch) // Get the reverse character of the current character
        num, ok := tmap[rch]
        if !ok { // If the reverse character is not in the second string
            continue
        }
        inum := num
        if inum == 1 { // If the reverse character appears only once in the second string
            delete(tmap, rch) // Remove it from the HashMap
        } else {
            tmap[rch] = inum - 1 // If the reverse character appears more than once in the second string, decrement its frequency
        }
        opa++ // Increment the counter for opposite characters
    }

    // Print the results
    fmt.Println(ura, opa)
}

// Reverse the given character
func reverse(ch rune) rune {
    if ch >= 'a' && ch <= 'z' { // If the character is lowercase
        return ch - 32 // Return its uppercase version
    } else {
        return ch + 32 // If the character is uppercase, return its lowercase version
    }
}

