
package main

import "fmt"

func main() {
	record_of_movements := input()
	x, y := 0, 0
	d_movement := map[string][2]int{
		"L": [2]int{0, -1},
		"R": [2]int{0, 1},
		"U": [2]int{1, 0},
		"D": [2]int{-1, 0},
	}
	d := map[[2]int]string{
		[2]int{x, y}: "",
	}
	bug := false

	for _, move := range record_of_movements {
		temp := [2]int{x, y}
		x += d_movement[move][0]
		y += d_movement[move][1]

		if [2]int{x, y}!= temp {
			for step := range d_movement {
				if [2]int{x+d_movement[step][0], y+d_movement[step][1]}!= temp && [2]int{x+d_movement[step][0], y+d_movement[step][1]}!= [2]int{0, 0} {
					bug = true
					break
				}
			}
		} else {
			bug = true
		}

		if bug {
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

