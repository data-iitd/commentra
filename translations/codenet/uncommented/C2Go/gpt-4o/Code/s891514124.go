package main

import (
	"fmt"
)

func main() {
	var S int
	fmt.Scan(&S)

	if S < 60 {
		fmt.Printf("0:0:%d\n", S)
	} else if S < 3600 {
		fmt.Printf("0:%d:%d\n", S/60, S%60)
	} else {
		fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)
	}
}

// <END-OF-CODE>
