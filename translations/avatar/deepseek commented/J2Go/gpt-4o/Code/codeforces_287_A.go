package main

import (
	"fmt"
)

func main() {
	var str [4]string // Declare and initialize an array of strings
	for i := 0; i < 4; i++ {
		fmt.Scan(&str[i]) // Read input strings into the array
	}

	yes := 0
	for u := 0; u < 3; u++ { // Compare characters in the array
		for i := 0; i < 3; i++ {
			if (str[u][i] == str[u][i+1] && (str[u+1][i] == str[u][i] || str[u+1][i+1] == str[u][i])) ||
				(str[u+1][i] == str[u+1][i+1] && (str[u][i] == str[u+1][i] || str[u][i+1] == str[u+1][i])) {
				yes = 1
				fmt.Println("YES")
				break
			}
		}
		if yes == 1 {
			break
		}
	}
	if yes == 0 {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
