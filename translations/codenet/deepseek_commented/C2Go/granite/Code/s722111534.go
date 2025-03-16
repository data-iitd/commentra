
package main

import "fmt"

func main() {
  var hcell, wcell, hpaint, wpaint, nblack, nwhite int

  // Read the number of cells in the grid and the number of rows/columns to be painted
  fmt.Scan(&hcell, &wcell)
  fmt.Scan(&hpaint, &wpaint)

  // Calculate the number of black cells
  nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

  // Calculate the number of white cells
  nwhite = (hcell * wcell) - nblack

  // Print the number of white cells
  fmt.Println(nwhite)
}

