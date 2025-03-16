package main

import (
	"fmt"
)

func main() {
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int

	fmt.Scan(&hcell, &wcell)
	fmt.Scan(&hpaint, &wpaint)

	nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)
	nwhite = (hcell * wcell) - nblack

	fmt.Println(nwhite)
}

