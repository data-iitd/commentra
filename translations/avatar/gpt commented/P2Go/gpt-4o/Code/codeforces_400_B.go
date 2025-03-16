package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	differences := make(map[int]struct{})

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		indexS := strings.Index(s, "S")
		indexG := strings.Index(s, "G")
		difference := indexS - indexG

		differences[difference] = struct{}{}
	}

	// Check if any of the calculated differences are negative
	negativeFound := false
	for diff := range differences {
		if diff < 0 {
			negativeFound = true
			break
		}
	}

	if negativeFound {
		fmt.Println(-1)
	} else {
		fmt.Println(len(differences))
	}
}

// <END-OF-CODE>
