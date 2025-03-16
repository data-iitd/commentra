package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of inputs to be taken
	var pya int
	fmt.Scan(&pya)
	
	// Initialize an empty list to store the inputs
	arre := []string{}
	
	// Read pya number of inputs and convert them to lowercase, then append to arre
	for i := 0; i < pya; i++ {
		input, _ := reader.ReadString('\n')
		arre = append(arre, strings.ToLower(strings.TrimSpace(input)))
	}
	
	// Read the original string
	oString, _ := reader.ReadString('\n')
	oString = strings.ToLower(strings.TrimSpace(oString))
	
	// Read the first letter and determine the second letter
	letter1, _ := reader.ReadString('\n')
	letter1 = strings.ToLower(strings.TrimSpace(letter1))
	letter2 := "b"
	if letter1 == "a" {
		letter2 = "a"
	}
	
	// Initialize a list of zeros with the length of oString
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	
	// Iterate over each string in arre and check if it exists in oString
	for _, x := range arre {
		index := strings.Index(oString, x)
		for index != -1 {
			for i := index; i < index+len(x); i++ {
				setcito[i] = true
			}
			index = strings.Index(oString[index+1:], x) + index + 1
		}
	}
	
	// Convert oString to a slice for easy manipulation
	oStringSlice := []rune(oString)
	
	// Update the characters in oString based on the setcito indices and letter rules
	for i := range oStringSlice {
		if _, ok := setcito[i]; ok {
			letter := letter1
			if string(oStringSlice[i]) == letter1 {
				letter = letter2
			}
			if oStringSlice[i] >= 'a' && oStringSlice[i] <= 'z' {
				oStringSlice[i] = rune(letter[0])
			} else {
				oStringSlice[i] = rune(strings.ToUpper(letter)[0])
			}
		}
	}
	
	// Print the modified oString
	fmt.Println(string(oStringSlice))
}

