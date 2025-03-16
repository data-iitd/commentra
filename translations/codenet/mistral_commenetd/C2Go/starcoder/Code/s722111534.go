<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the height and width of the grid: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	hcell, wcell := strings.Split(input, " ")
	hcell, _ = strconv.Atoi(hcell)
	wcell, _ = strconv.Atoi(wcell)
	fmt.Print("Enter the number of rows and columns to be painted with black and white respectively: ")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	hpaint, wpaint := strings.Split(input, " ")
	hpaint, _ = strconv.Atoi(hpaint)
	wpaint, _ = strconv.Atoi(wpaint)
	nblack := (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)
	nwhite := (hcell * wcell) - nblack
	fmt.Println(nwhite)
}

