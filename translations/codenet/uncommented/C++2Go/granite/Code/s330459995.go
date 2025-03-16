
package main

import "fmt"

func main() {
	var W, H, x, y, r int
	fmt.Scan(&W, &H, &x, &y, &r)
	if x-r < 0 || x+r > W || y-r < 0 || y+r > H {
		fmt.Println("No")
	} else if x-r >= 0 && x+r <= W && y-r >= 0 && y+r <= W {
		fmt.Println("Yes")
	}
}

