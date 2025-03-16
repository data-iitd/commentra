// Read an integer input which represents the number of strings to be added to the list
pya := 0
fmt.Scan(&pya)

// Initialize an empty list to store the input strings
arre := make([]string, 0)

// Loop to collect 'pya' number of strings from user input
for pya > 0 {
	pya-- // Decrement the counter
	// Append the lowercase version of the input string to the list
	arre = append(arre, strings.ToLower(input()))
}

// Read the original string from user input
oString := input()

// Convert the original string to lowercase for comparison
lowString := strings.ToLower(oString)

// Read a letter from user input and convert it to lowercase
letter1 := strings.ToLower(input())[0]

// Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
letter2 := "a"
if letter1 != "a" {
	letter2 = "b"
}

// Initialize a list to track valid indices for replacement
valid := make([]int, len(oString))

// Create a set to store unique indices where replacements will occur
setcito := make(map[int]bool)

// Loop through each string in the list 'arre'
for _, x := range arre {
	// Check if the current string 'x' is found in the lowercase version of the original string
	if strings.Index(lowString, x) >= 0 {
		wat := 0 // Initialize a variable to track the search position
		for {
			// Find the index of the current string 'x' starting from position 'wat'
			index := strings.Index(lowString, x, wat)
			if index < 0 {
				break // Exit the loop if no more occurrences are found
			}
			// Add the indices of the found string to the set for replacement
			for i := index; i < index+len(x); i++ {
				setcito[i] = true
			}
			wat = index + 1 // Move the search position forward
		}
	}
}

// Convert the original string to a list for mutable operations
oString = []rune(oString)

// Loop through the indices stored in 'setcito' for replacement
for i := range setcito {
	// Determine which letter to use for replacement based on the original character
	letter := letter1
	if lowString[i] != letter1 {
		letter = letter2
	}
	// Replace the character in the original string with the chosen letter, maintaining case
	oString[i] = rune(letter)
}

// Print the modified string without spaces between characters
for _, x := range oString {
	fmt.Print(string(x))
}

// Print a newline at the end
fmt.Println()

