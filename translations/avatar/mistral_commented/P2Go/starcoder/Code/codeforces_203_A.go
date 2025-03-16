#######
# Code
#######

// Input the string of numbers separated by spaces and split it into a list
var xxs []string
fmt.Scanf("%s", &xxs)

// Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
x, t, a, b, da, db := 0, 0, 0, 0, 0, 0
x, t, a, b, da, db = strconv.Atoi(xxs[0]), strconv.Atoi(xxs[1]), strconv.Atoi(xxs[2]), strconv.Atoi(xxs[3]), strconv.Atoi(xxs[4]), strconv.Atoi(xxs[5])

// Define the main function to perform the logic of the program
func main() {
    // Check if x is equal to zero
    if x == 0 {
        // If yes, print "YES" and return
        fmt.Println("YES")
        return
    }

    // Calculate the minimum time it takes for a and b to reach x
    a_time := min(a/da, t-1)
    b_time := min(b/db, t-1)

    // Loop through all possible combinations of a_time and b_time
    for i := 0; i <= a_time; i++ {
        for j := 0; j <= b_time; j++ {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if a - da * i == x || b - db * j == x {
                // If yes, print "YES" and return
                fmt.Println("YES")
                return
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if (a - da * i) + (b - db * j) == x {
                // If yes, print "YES" and return
                fmt.Println("YES")
                return
            }
        }
    }
}

// Call the main function and assign the result to a variable ff
var ff string
ff = main()

// If the result is "Result Not Found", print "NO"
if ff == "Result Not Found" {
    fmt.Println("NO")
}

