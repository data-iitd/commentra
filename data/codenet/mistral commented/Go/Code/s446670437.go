package main

import "fmt"

// Define a Dice struct with a Numbers slice to store the numbers on the dice.
type Dice struct {
	Nums []int
}

// Function to rotate the dice in a given direction by a given number of times.
func (d *Dice) rotate(direction string, times int) {
	times %= 4 // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch direction {
	case "W": // West direction rotation logic
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[2], d.Nums[5], d.Nums[3] = d.Nums[2], d.Nums[5], d.Nums[3], d.Nums[0]
		}
	case "E": // East direction rotation logic
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[2], d.Nums[5], d.Nums[3] = d.Nums[3], d.Nums[0], d.Nums[2], d.Nums[5]
		}
	case "N": // North direction rotation logic
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[4], d.Nums[5], d.Nums[1] = d.Nums[1], d.Nums[0], d.Nums[4], d.Nums[5]
		}
	case "S": // South direction rotation logic
		for i := 0; i < times; i++ {
			d.Nums[5], d.Nums[1], d.Nums[0], d.Nums[4] = d.Nums[1], d.Nums[0], d.Nums[4], d.Nums[5]
		}
	}
}

// Function to roll the dice in a given direction by a given number of times.
func (d *Dice) roll(direction string, times int) {
	times %= 4 // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch direction {
	case "R": // Right direction roll logic
		for i := 0; i < times; i++ {
			d.Nums[3], d.Nums[1], d.Nums[2], d.Nums[4] = d.Nums[1], d.Nums[2], d.Nums[4], d.Nums[3]
		}
	case "L": // Left direction roll logic
		for i := 0; i < times; i++ {
			d.Nums[3], d.Nums[1], d.Nums[2], d.Nums[4] = d.Nums[4], d.Nums[3], d.Nums[1], d.Nums[2]
		}
	}
}

// Function to print the current status of the dice.
func (d *Dice) printStatus() {
	status :=
		`	　　　 _ _ _ _
	     _ _ _|_%3d_|_ _ _ _ _ _
	    |_%3d_|_%3d_|_%3d_|_%3d_|
	 　       |_%3d_|
	`
	fmt.Printf(status, d.Nums[0], d.Nums[3], d.Nums[1], d.Nums[2], d.Nums[4], d.Nums[5])
	fmt.Println()
}

// Function to get the index of a target number in a given slice.
func getIndex(nums []int, target int) (index int) {
	for i, v := range nums {
		if target == v {
			index = i
			break
		} else {
			index = -1
		}
	}
	return index
}

// Function to check if two dice have the same numbers.
func (d *Dice) isEqual(other Dice) bool {
	for i, v := range d.Nums {
		if v != other.Nums[i] {
			return false
		}
	}
	return true
}

// Main function to read user input and check if two dice are the same after certain rotations and rolls.
func main() {
	dice1 := Dice{
		make([]int, 6),
	}
	dice2 := Dice{
		make([]int, 6),
	}
	for i := 0; i < 6; i++ {
		var n int
		fmt.Scan(&n)
		dice1.Nums[i] = n
	}
	for i := 0; i < 6; i++ {
		var n int
		fmt.Scan(&n)
		dice2.Nums[i] = n
	}

	directionOrder := []string{"N", "S", "W", "E"} // Order of directions to rotate
	rollOrder := []string{"R", "L"}             // Order of rolls
	flag := false

	// Check all possible combinations of rotations and rolls to find if the dice are the same.
	CHECK:
		for i := 0; i <= 2; i++ {
			for j := 0; j <= 2; j++ {
				for _, direction := range directionOrder {
					for _, roll := range rollOrder {
						tmp := new(Dice)
						tmp.Nums = append([]int{}, dice2.Nums...)
						tmp.rotate(direction, i)
						tmp.roll(roll, j)
						if tmp.isEqual(dice1) {
							flag = true
							break CHECK
						}
					}
				}
			}
		}
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
