// Importing the required utility package
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function
func main() {

	// Declaring the required variables
	var n, m int
	var arr []int
	var gen [11]int
	var ans int64

	// Getting the input from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &m)

	// Creating an array of size n to store the input integers
	arr = make([]int, n)

	// Getting the input integers and storing them in the arr array
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
		gen[arr[i]]++
	}

	// Calculating the answer
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			// Skipping the case when i and k are equal to avoid double counting
			if i!= k {
				// Multiplying the count of i and k and adding it to the answer
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	// Printing the answer divided by 2
	fmt.Println(ans / 2)
}

