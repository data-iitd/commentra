
// Define variables x and y by unpacking the tuple returned by the map function
x, y := map(int, strings.Split(input(), " "))

// Helper functions for simplifying input process
func num_inp() int {
    return int(input())
}

func arr_inp() []int {
    return strings.Split(input(), " ")
}

func sp_inp() []int {
    return strings.Split(input(), " ")
}

func str_inp() string {
    return input()
}

// Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
fmt.Println(max(x + y - 3 + ((y - x) % 3 > 0), 0))

