
package main

import "fmt"

// Define a custom data structure
type data struct {
	n, m       int // dimensions of the images
	nImg, mImg []string // image data as strings
}

// Main function
func main() {
	// Initialize a new data object
	d := newData()
	// Check if data already exists
	if d.exist() {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// Initialize a new data object
func newData() data {
	// Read dimensions from user input
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	// Load image data as strings
	nImg := load(n)
	mImg := load(m)

	// Initialize data object with loaded data
	return data{n: n, m: m, nImg: nImg, mImg: mImg}
}

// Load image data as strings
func load(cnt int) []string {
	// Allocate memory for image data
	ret := make([]string, cnt)
	// Read image data from user input
	for i := 0; i < cnt; i++ {
		fmt.Scanf("%s", &ret[i])
	}

	// Return loaded image data
	return ret
}

// Check if data already exists in the larger image
func (d data) exist() bool {
	// Iterate through all possible positions in larger image
	for i := 0; i <= d.n-d.m; i++ {
		for j := 0; j <= d.n-d.m; j++ {
			// Check if current position matches the smaller image
			if d.match(i, j) {
				// If match is found, return true
				return true
			}
		}
	}

	// If no match is found, return false
	return false
}

// Check if smaller image matches at current position in larger image
func (d data) match(x, y int) bool {
	// Iterate through each pixel in smaller image
	for i := 0; i < d.m; i++ {
		for j := 0; j < d.m; j++ {
			// Check if corresponding pixel in larger image matches
			if d.nImg[x+i][y+j] != d.mImg[i][j] {
				// If mismatch is found, return false
				return false
			}
		}
	}

	// If all pixels match, return true
	return true
}
