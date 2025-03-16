package main

import "fmt"

/*
展開図の展開の仕方を固定して、回転動作によってどのように展開図の数字が移るかを記録する。
展開図は次の通り。手前の目2番を中心に据える展開の仕方。
         ___
    ____|_1_|_______
    |_4_|_2_|_3_|_5_|
        |_6_|

サイコロの状態は上面と前面を指定することで一意に決定される。それぞれを指定された目に揃えて、
展開図の3番を記録。
入力された二つのサイコロについて上面前面を揃えた上で右側面の値を比較することで判定。
で、できるかと思ったが、サイコロの各面の数字がすべて異なるという制約は今回の問題にはないので、
この判定方法は不完全。

よって、力ずくで全通り調べる。
*/

// Dice struct represents a dice with its six faces numbered.
type Dice struct {
	Nums []int // Array to hold the numbers on the faces of the dice
}

// rotate method rotates the dice in a specified direction a certain number of times.
func (d *Dice) rotate(direction string, times int) {
	times %= 4 // Normalize the number of rotations to be within 0-3
	switch direction {
	case "W": // Rotate West
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[2], d.Nums[5], d.Nums[3] = d.Nums[2], d.Nums[5], d.Nums[3], d.Nums[0]
		}
	case "E": // Rotate East
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[2], d.Nums[5], d.Nums[3] = d.Nums[3], d.Nums[0], d.Nums[2], d.Nums[5]
		}
	case "N": // Rotate North
		for i := 0; i < times; i++ {
			d.Nums[0], d.Nums[4], d.Nums[5], d.Nums[1] = d.Nums[1], d.Nums[0], d.Nums[4], d.Nums[5]
		}
	case "S": // Rotate South
		for i := 0; i < times; i++ {
			d.Nums[5], d.Nums[1], d.Nums[0], d.Nums[4] = d.Nums[1], d.Nums[0], d.Nums[4], d.Nums[5]
		}
	}
}

// roll method rolls the dice in a specified direction a certain number of times.
func (d *Dice) roll(direction string, times int) {
	times %= 4 // Normalize the number of rolls to be within 0-3
	switch direction {
	case "R": // Roll Right
		for i := 0; i < times; i++ {
			d.Nums[3], d.Nums[1], d.Nums[2], d.Nums[4] = d.Nums[1], d.Nums[2], d.Nums[4], d.Nums[3]
		}
	case "L": // Roll Left
		for i := 0; i < times; i++ {
			d.Nums[3], d.Nums[1], d.Nums[2], d.Nums[4] = d.Nums[4], d.Nums[3], d.Nums[1], d.Nums[2]
		}
	}
}

// printStatus method prints the current status of the dice in a formatted manner.
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

// getIndex function returns the index of a target number in the nums slice.
func getIndex(nums []int, target int) (index int) {
	for i, v := range nums {
		if target == v {
			index = i // Found the target, return its index
			break
		} else {
			index = -1 // Target not found, return -1
		}
	}
	return index
}

// isEqual method checks if two dice are in the same state (same numbers on each face).
func (d *Dice) isEqual(other Dice) bool {
	for i, v := range d.Nums {
		if v != other.Nums[i] {
			return false // If any face differs, return false
		}
	}
	return true // All faces match, return true
}

// main function to execute the dice comparison logic.
func main() {
	// Initialize two dice
	dice1 := Dice{
		make([]int, 6), // Create a slice for the first dice
	}
	dice2 := Dice{
		make([]int, 6), // Create a slice for the second dice
	}

	// Input numbers for the first dice
	for i := 0; i < 6; i++ {
		var n int
		fmt.Scan(&n) // Read input for each face
		dice1.Nums[i] = n // Assign input to the dice
	}

	// Input numbers for the second dice
	for i := 0; i < 6; i++ {
		var n int
		fmt.Scan(&n) // Read input for each face
		dice2.Nums[i] = n // Assign input to the dice
	}

	// Define the order of directions and rolls for testing
	directionOrder := []string{"N", "S", "W", "E"}
	rollOrder := []string{"R", "L"}
	flag := false // Flag to indicate if a match is found

	CHECK: // Label for breaking out of nested loops
	// Check all combinations of rotations and rolls
		for i := 0; i <= 2; i++ { // Rotate 0 to 2 times
			for j := 0; j <= 2; j++ { // Roll 0 to 2 times
				for _, direction := range directionOrder { // Iterate through directions
					for _, roll := range rollOrder { // Iterate through roll directions
						tmp := new(Dice) // Create a temporary dice
						tmp.Nums = append([]int{}, dice2.Nums...) // Copy the numbers from dice2
						tmp.rotate(direction, i) // Rotate the temporary dice
						tmp.roll(roll, j) // Roll the temporary dice
						if tmp.isEqual(dice1) { // Check if it matches dice1
							flag = true // Match found
							break CHECK // Break out of all loops
						}
					}
				}
			}
		}
	// Output the result based on the flag
	if flag {
		fmt.Println("Yes") // If a match was found
	} else {
		fmt.Println("No") // If no match was found
	}
}
