package main

import "fmt"

func main() {
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int

	fmt.Scanf("%d %d", &hcell, &wcell)
	fmt.Scanf("%d %d", &hpaint, &wpaint)

	nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)
	nwhite = (hcell * wcell) - nblack

	fmt.Printf("%d\n", nwhite)
}

