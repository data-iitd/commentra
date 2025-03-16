package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a Scanner object to read input from the user
	sc := bufio.NewScanner(os.Stdin)
	
	// Initializing an array to hold 4 strings
	var str [4]string
	
	// Loop to read 4 strings from user input
	for i := 0; i < 4; i++ {
		sc.Scan()
		str[i] = sc.Text()
	}
	
	yes := 0
	
	// Outer loop to iterate through the first 3 strings
	for u := 0; u < 3; u++ {
		// Inner loop to check conditions on characters of the strings
		for i := 0; i < 3; i++ {
			// Check if the characters in the strings meet the specified conditions
			if (str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) || 
			   (str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i])) {
				yes = 1
				fmt.Println("YES")
				return
			}
		}
	}
	
	// If no matches were found, output "NO"
	if yes == 0 {
		fmt.Println("NO")
	}
}
