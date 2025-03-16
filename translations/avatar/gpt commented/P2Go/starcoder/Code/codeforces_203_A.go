// Read input values and split them into a list
xxs := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")

// Convert the input strings to integers
x, t, a, b, da, db := strconv.Atoi(xxs[0]), strconv.Atoi(xxs[1]), strconv.Atoi(xxs[2]), strconv.Atoi(xxs[3]), strconv.Atoi(xxs[4]), strconv.Atoi(xxs[5])

func main() {
    // Check if the target value x is zero
    if x == 0 {
        fmt.Println("YES") // If x is zero, print "YES" and return
        return
    }
    
    // Calculate the maximum time available for a and b, constrained by t
    a_time := min(a / da, t - 1)
    b_time := min(b / db, t - 1)
    
    // Iterate through all possible values of i and j within the calculated time limits
    for i := 0; i <= a_time; i++ {
        for j := 0; j <= b_time; j++ {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if a - da * i == x || b - db * j == x {
                fmt.Println("YES") // If found, print "YES" and return
                return
            }
            // Check if the sum of the remaining values of a and b equals x
            if (a - da * i) + (b - db * j) == x {
                fmt.Println("YES") // If found, print "YES" and return
                return
            }
        }
    }
    
    // If no valid combination is found, return
    fmt.Println("NO")
}

// Call the main function and store the result
ff := main()

// If the result indicates that no valid combination was found, print "NO"
if ff == "Result Not Found" {
    fmt.Println("NO")
}

