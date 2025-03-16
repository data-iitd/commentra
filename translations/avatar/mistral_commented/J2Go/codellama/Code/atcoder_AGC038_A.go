// Importing required packages for file I/O and Scanner
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Main method starts the execution of the program
func main() {
    sc := bufio.NewScanner(os.Stdin) // Initialize Scanner for user input
    bw := bufio.NewWriter(os.Stdout) // Initialize BufferedWriter for output
    var H, W, A, B int // Declare variables for height, width, A, and B

    // Read input values for H, W, A, and B
    sc.Scan()
    H, _ = strconv.Atoi(sc.Text())
    sc.Scan()
    W, _ = strconv.Atoi(sc.Text())
    sc.Scan()
    A, _ = strconv.Atoi(sc.Text())
    sc.Scan()
    B, _ = strconv.Atoi(sc.Text())

    // Check if the grid dimensions meet the conditions
    if W < 2*A || H < 2*B {
        fmt.Println(-1) // Print -1 if the conditions are not met
        return          // Exit the program
    }

    // Write the grid to the output
    for i := 0; i < H; i++ {
        for j := 0; j < W; j++ {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if (i < B && j < A) || (i >= B) && (j >= A) {
                bw.WriteString("0")
            } else {
                bw.WriteString("1")
            }
        }
        bw.WriteString("\n") // Move to the next line after writing a row
    }

    // Flush the buffer to write the output to the console
    bw.Flush()

}

