package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)

	res := []string{}
	punctuation := []string{",", ".", "!", "?"}

	for i := 0; i < len(s); i++ {
		if i >= 1 {
			if string(s[i]) == " " {
				if len(res) > 0 && res[len(res)-1] != "" {
					res = append(res, " ")
				}
			} else {
				if contains(punctuation, string(s[i])) {
					if len(res) > 0 && res[len(res)-1] == "" {
						res = res[:len(res)-1] // pop last element
					}
					res = append(res, string(s[i]))
					res = append(res, "") // add empty string
				} else {
					res = append(res, string(s[i]))
				}
			}
		} else {
			if string(s[i]) == " " {
				continue
			}
			if contains(punctuation, string(s[i])) {
				continue
			} else {
				res = append(res, string(s[i]))
			}
		}
	}

	fmt.Print(strings.Join(res, ""))
}

// Helper function to check if a string is in a slice
func contains(slice []string, item string) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
