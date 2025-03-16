// Take an integer 'n' as input from the user
n := 0
fmt.Scan(&n)

// Take a list 'm' as input from the user, where each element is a single character
var m []string
fmt.Scan(&m)

// Initialize a boolean variable 'possible' with a default value of True
possible := true

// Iterate through each unique character 'i' in the list 'm'
for _, i := range m {
    // Check if the character 'i' appears more than 'n/2 + 1' times in the list 'm'
    if strings.Count(strings.Join(m, ""), i) >= n/2+1 {
        // If the condition is true, set 'possible' to False and break the loop
        possible = false
        break
    }
}

// Print 'YES' if 'possible' is still True, otherwise print 'NO'
fmt.Println("YES" if possible else "NO")

