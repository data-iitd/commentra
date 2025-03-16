package main

import "fmt"

func main() {
	candeleIntere, b := 0, 0
	fmt.Scanf("%d %d", &candeleIntere, &b)
	s, restoSciolte := 0, 0
	for candeleIntere > 0 || restoSciolte >= b {
		candeleIntere += restoSciolte / b
		restoSciolte %= b
		s += candeleIntere
		restoSciolte += candeleIntere % b
		candeleIntere /= b
	}
	fmt.Println(s)
}

