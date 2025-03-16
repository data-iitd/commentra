// Read two integers n and k from input, where n is the total number of elements and k is the position of interest
var n, k int
fmt.Scanf("%d %d", &n, &k)

// Read the string of values (v) from input
var v string
fmt.Scanf("%s", &v)

// Define the directions for movement: LEFT and RIGHT
const (
    LEFT = iota
    RIGHT
)

// Determine if we should move LEFT or RIGHT based on the position k
// If k is closer to the start (LEFT), f will be True; otherwise, it will be False
var f bool
if k-1 < n-k {
    f = true
}

// Calculate the minimum number of moves needed to reach the desired position
m := min(k-1, n-k)

// Initialize an empty list to store the sequence of moves and prints
a := make([]string, 0)

// Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
for i := 0; i < m; i++ {
    a = append(a, fmt.Sprintf("%s", LEFT))
    if!f {
        a = append(a, fmt.Sprintf("%s", RIGHT))
    }
}

// Append the print commands for each character in the string v
// The slicing reverses the order of characters if moving RIGHT (f is True)
for _, i := range v[:: -1 + 2 * f] {
    a = append(a, fmt.Sprintf("PRINT %c", i))
    a = append(a, fmt.Sprintf("%s", RIGHT))
}

// Print the final sequence of moves and print commands, excluding the last move
fmt.Println(strings.Join(a[:len(a)-1], "\n"))

