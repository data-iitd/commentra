
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

// Function to calculate 2 raised to the power of a given number
func pow2(a int) int {
	ret := 1 // Initialize result to 1
	for i := 0; i < a; i++ { // Multiply result by 2 for each iteration of the loop
		ret *= 2
	}
	return ret // Return the final result
}

// Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
func count(hw [][]int, a, b int) int {
	sum := 0 // Initialize sum to 0
	for i := 0; i < len(hw); i++ { // Iterate through each row of the 2D grid
		for j := 0; j < len(hw[0]); j++ { // Iterate through each column of the current row
			if ((a&(1<<i)) > 0 && (b&(1<<j)) > 0 && hw[i][j] == 1) { // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
				sum++
			}
		}
	}
	return sum // Return the final sum
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter height, width, and target count: ")
	hwk := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	h, _ := strconv.Atoi(hwk[0])
	w, _ := strconv.Atoi(hwk[1])
	k, _ := strconv.Atoi(hwk[2])
	hw := make([][]int, h)
	for i := 0; i < h; i++ {
		hw[i] = make([]int, w)
	}
	for i := 0; i < h; i++ {
<<<<<<< HEAD
		hw[i], _ = readLineIntSlice(reader)
=======
		hw[i], _ = readLineStr(reader)
>>>>>>> 98c87cb78a (data updated)
	}
	sum := 0
	for i := 0; i < pow2(h); i++ { // Iterate through all possible binary combinations of height
		for j := 0; j < pow2(w); j++ { // Iterate through all possible binary combinations of width
			if count(hw, i, j) == k { // If the number of 1's in the current combination matches the target count, increment sum
				sum++
			}
		}
	}
	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return string(str)
}

<<<<<<< HEAD
func readLineIntSlice(reader *bufio.Reader) ([]int, error) {
	line, err := readLine(reader)
	if err!= nil {
		return nil, err
	}
	var result []int
	for _, item := range strings.Split(line, " ") {
		if item!= "" {
			val, err := strconv.Atoi(item)
			if err!= nil {
				return nil, err
			}
			result = append(result, val)
		}
	}
	return result, nil
=======
func readLineStr(reader *bufio.Reader) ([]int, error) {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return nil, err
	}
	return strToIntArray(str), nil
}

func strToIntArray(str string) []int {
	var ret []int
	tmp := strings.Split(str, " ")
	for _, s := range tmp {
		if s!= "" {
			ret = append(ret, toInt(s))
		}
	}
	return ret
}

func toInt(s string) int {
	ret, _ := strconv.Atoi(s)
	return ret
>>>>>>> 98c87cb78a (data updated)
}

func pow2(a int) int {
	ret := 1 // Initialize result to 1
	for i := 0; i < a; i++ { // Multiply result by 2 for each iteration of the loop
		ret *= 2
	}
	return ret // Return the final result
}

<<<<<<< HEAD
=======
// Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
>>>>>>> 98c87cb78a (data updated)
func count(hw [][]int, a, b int) int {
	sum := 0 // Initialize sum to 0
	for i := 0; i < len(hw); i++ { // Iterate through each row of the 2D grid
		for j := 0; j < len(hw[0]); j++ { // Iterate through each column of the current row
			if ((a&(1<<i)) > 0 && (b&(1<<j)) > 0 && hw[i][j] == 1) { // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
				sum++
			}
		}
	}
	return sum // Return the final sum
}

