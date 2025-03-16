// Importing required libraries
import "math"

// Taking input of n and number of distinct numbers
var n, num int
fmt.Scanf("%d %d", &n, &num)

// Creating a set of distinct numbers
var num_set = make(map[int]bool)
for i := 0; i < num; i++ {
    var temp int
    fmt.Scanf("%d", &temp)
    num_set[temp] = true
}

// Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
var two_times_set = make(map[int]bool)
for i := range num_set {
    // Initializing a counter to keep track of the number of times 2 is divided
    power_of_two := 0

    // Dividing i by 2 repeatedly until it is no longer odd
    for j := i; j > 0; j >>= 1 {
        if j&1 == 1 {
            power_of_two += 1
        }
    }

    // If the number of times 2 is divided is not exactly 1, then the answer is 0
    if power_of_two > 1 {
        fmt.Println(0)
        break
    }

    // Add the power of 2 to two_times_set
    two_times_set[power_of_two] = true
}

// If the size of two_times_set is not exactly 1, then the answer is 0
if len(two_times_set)!= 1 {
    fmt.Println(0)
    return
}

// Finding the least common multiple of all numbers in num_set
var num_list []int
for i := range num_set {
    num_list = append(num_list, i)
}

// Finding the least common multiple of the first number and the next number
lcm := num_list[0]
for i := 1; i < len(num_list); i++ {
    lcm = lcm * num_list[i] / int(math.GCD(float64(lcm), float64(num_list[i])))
}

// Printing the answer
fmt.Println((num - lcm/2) / lcm + 1)

