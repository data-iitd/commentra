

package main

import "fmt"

func main() {
  var h, w, hh, ww int
  fmt.Scan(&h, &w, &hh, &ww)
  difference_h := h - hh
  difference_w := w - ww
  fmt.Printf("The area of the rectangle is: %d\n", difference_h * difference_w)
}

