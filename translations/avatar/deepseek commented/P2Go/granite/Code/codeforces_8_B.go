

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the movements of a character:")
	recordOfMovements, _ := reader.ReadString('\n')
	recordOfMovements = strings.TrimSpace(recordOfMovements)
	x, y := 0, 0
	dMovement := map[string][2]int{"L": {0, -1}, "R": {0, 1}, "U": {1, 0}, "D": {-1, 0}}
	d := map[[2]int]string{{x, y}: ""}
	bug := false
	for _, move := range strings.Split(recordOfMovements, "") {
		temp := [2]int{x, y}
		x += dMovement[move][0]
		y += dMovement[move][1]
		if _, ok := d[[2]int{x, y}];!ok {
			for _, step := range []string{"L", "R", "U", "D"} {
				if [2]int{x + dMovement[step][0], y + dMovement[step][1]}!= temp && [2]int{x + dMovement[step][0], y + dMovement[step][1]}!= [2]int{0, 0} && _, ok := d[[2]int{x + dMovement[step][0], y + dMovement[step][1]}; ok {
					bug = true
					break
				}
			}
		} else {
			bug = true
			break
		}
		d[[2]int{x, y}] = ""
	}
	if bug {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}

