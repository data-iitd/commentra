package main

import (
	"fmt"
)

func main() {
	var candeleIntere, b int
	fmt.Scan(&candeleIntere, &b)

	s := 0
	restoSciolte := 0

	for candeleIntere > 0 || restoSciolte >= b {
		candeleIntere += restoSciolte / b
		restoSciolte %= b
		s += candeleIntere
		restoSciolte += candeleIntere % b
		candeleIntere /= b
	}

	fmt.Println(s)
}

// <END-OF-CODE>
