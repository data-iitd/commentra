
package main

import (
	"fmt"
)

func main() {
	var h, w, hh, ww int
	fmt.Scan(&h, &w, &hh, &ww)
	difference_h := h - hh
	difference_w := w - ww
	fmt.Println("The area of the rectangle is: ", difference_h*difference_w)
}

