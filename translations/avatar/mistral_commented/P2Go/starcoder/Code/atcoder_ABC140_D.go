#######
# Code
#######

// Import necessary libraries
import "container/list"

// Function to parse input line by line
func parser() (data []string) {
// Continuously parse input lines
    for {
        data = strings.Fields(input())
// Process each token in the input line
        for _, number := range data {
// Check if the token is empty or not
            if len(number) > 0 {
// Yield the token as a result of the function
                yield number
            }
        }
    }
}

// Create a parser object
input_parser := parser()

// Function to get the next token from the parser
func gw() string {
// Get the next token from the parser
    global input_parser
    return <-input_parser
}

// Function to get the next integer from the parser
func gi() int {
// Get the next token as a string
    data := gw()
// Convert the token to an integer
    return int(data)
}

// Global variables
const MOD = 1e9 + 7

// Import additional libraries for scientific computing
import "math"
import "sort"

// Define a deque for segment count
var seg_cnt list.List

// Get the number of segments in the string
var N int
N = gi()

// Get the number of queries
var K int
K = gi()

// Get the string S
var S string
S = gw()

// Initialize segment count
seg_cnt = list.New()

// Iterate through the string and count the number of segments
for i := 0; i < N - 1; i++ {
// Check if the current character is different from the next character
    if S[i]!= S[i + 1] {
// Add 1 to the segment count
        seg_cnt.PushBack(1)
    }
}

// Calculate the current happiness
var cur_happy int
cur_happy = N - 1 - seg_cnt.Len()

// Check if the number of queries is greater than or equal to the number of segments
if 2 * K >= seg_cnt.Len() {
// If yes, then the answer is the total number of segments
    ans := N - 1
// Otherwise, the answer is the current happiness plus twice the number of queries
} else {
    ans := cur_happy + 2 * K
}

// Print the answer
fmt.Println(ans)

