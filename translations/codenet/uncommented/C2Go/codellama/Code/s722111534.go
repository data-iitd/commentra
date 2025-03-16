package main

import "fmt"

func main() {
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int
	// 順にマス行、マス列、塗る行、塗る列、塗られたマス、白いマス
	fmt.Scanf("%d %d", &hcell, &wcell)
	fmt.Scanf("%d %d", &hpaint, &wpaint)
	nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)
	nwhite = (hcell*wcell) - nblack
	fmt.Println(nwhite)
}
