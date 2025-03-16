package main

import (
	"fmt"
	"strconv"
)

func main() {
	var ip string
	fmt.Scan(&ip) // Taking an input from the user and storing it in the variable `ip`.
	st := ""      // Initializing an empty string `st`.

	if len(ip) != 1 { // Checking if the length of the input `ip` is not equal to 1.
		if ip[0] == '9' { // Checking if the first character of `ip` is "9".
			st = "9"      // Assigning "9" to `st`.
			ip = ip[1:]  // Removing the first character from `ip`.
		}
		for _, i := range ip { // Iterating over the remaining characters in `ip`.
			num, _ := strconv.Atoi(string(i)) // Converting the character to an integer.
			if num > 4 { // Checking if the integer value of the character is greater than 4.
				n := 9 - num // Calculating the difference between 9 and the integer value.
				st += strconv.Itoa(n) // Converting it to a string and appending it to `st`.
			} else { // If the integer value is not greater than 4.
				st += string(i) // Simply appending the character to `st`.
			}
		}
	} else { // If the length of `ip` is 1.
		st = ip // Assigning `ip` directly to `st`.
	}
	result, _ := strconv.Atoi(st) // Converting `st` to an integer.
	fmt.Println(result) // Printing the integer value of `st`.
}

// <END-OF-CODE>
