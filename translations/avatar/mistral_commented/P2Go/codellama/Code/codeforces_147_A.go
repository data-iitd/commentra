
package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take user input as a string 's'
	var s string
	fmt.Scan(&s)

	// Initialize an empty list 'res' to store the final result
	res := []string{}

	// Define a list 'punctuation' containing all the punctuation marks
	punctuation := []string{",", ".", "!", "?"}

	// Iterate through each character 'i' in the string 's'
	for i := 0; i < len(s); i++ {

		// If current character is a space and previous character is not empty,
		// append the space to the result list
		if i >= 1 {
			if s[i] == ' ' && res[len(res)-1] != "" {
				// Append space to the result list
				res = append(res, s[i])
			} else {
				continue
			}
		}

		// If current character is not a space and is a punctuation mark,
		// check if the previous character is empty, if yes then pop the last character from the result list
		// and append the current punctuation mark along with an empty string
		if s[i] in punctuation {
			if res[len(res)-1] == "" {
				res = res[:len(res)-1]
				res = append(res, s[i])
				res = append(res, "")
			} else {
				res = append(res, s[i])
			}
		}

		// If current character is not a space and is not a punctuation mark,
		// simply append it to the result list
		else {
			res = append(res, s[i])
		}
	}

	// Join all the elements of the result list and print the final string
	fmt.Println(strings.Join(res, ""))
}

