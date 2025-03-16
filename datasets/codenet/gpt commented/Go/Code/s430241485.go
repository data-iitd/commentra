package main

import "fmt"

func main() {
    // Declare two string variables to hold input values
	var s, t string
    
    // Read two strings from standard input
	fmt.Scan(&s, &t)
    
    // Print the concatenation of the second string followed by the first string
	fmt.Println(t + s)
}
