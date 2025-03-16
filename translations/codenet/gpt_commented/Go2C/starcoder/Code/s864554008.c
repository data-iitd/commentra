


import "fmt"

// Define a struct to hold the dimensions and images
type data struct {
	n, m       int        // n: number of rows in the first image, m: number of rows in the second image
	nImg, mImg []string   // nImg: first image as a slice of strings, mImg: second image as a slice of strings
}

func main() {
	// Create a new data instance and check for the existence of a match
	d := newData()
	if d.exist() {
		fmt.Println("Yes") // Print "Yes" if a match exists
	} else {
		fmt.Println("No")  // Print "No" if no match is found
	}
}

// Function to read input dimensions and images, returning a data instance
func newData() data {
	var n, m int
	// Read the dimensions of the images from standard input
	scanf("%d %d", &n, &m)
	// Load the first image and the second image based on the dimensions
	nImg := load(n)
	mImg := load(m)

	// Return a data instance containing the dimensions and images
	return data{n: n, m: m, nImg: nImg, mImg: mImg}
}

// Function to load an image of given count from standard input
func load(cnt int) []string {
	ret := make([]string, cnt) // Create a slice to hold the image strings
	for i := 0; i < cnt; i++ {
		// Read each line of the image into the slice
		scanf("%s", &ret[i])
	}

	// Return the loaded image
	return ret
}

// Method to check if the second image exists within the first image
func (d data) exist() bool {
	// Iterate over possible starting positions in the first image
	for i := 0; i <= d.n-d.m; i++ {
		for j := 0; j <= d.n-d.m; j++ {
			// Check if the second image matches the first image at the current position
			if d.match(i, j) {
				return true // Return true if a match is found
			}
		}
	}

	// Return false if no match is found after checking all positions
	return false
}

// Method to check if the second image matches the first image at a specific position
func (d data) match(x, y int) bool {
	// Iterate over each cell of the second image
	for i := 0; i < d.m; i++ {
		for j := 0; j < d.m; j++ {
			// Compare the corresponding cells of the two images
			if d.nImg[x+i][y+j]!= d.mImg[i][j] {
				return false // Return false if any cell does not match
			}
		}
	}

	// Return true if all cells match
	return true
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// Function to print output to stdout
func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

// Function to print output to stderr
func eprintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// Function to read input from stdin
func scanf(format string, a...interface{}) {
	fmt.Scanf(format, a...)
}

// 