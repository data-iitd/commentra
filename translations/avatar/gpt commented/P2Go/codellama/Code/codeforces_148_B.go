// Read the number of princesses, dragons, time, and other parameters from user input
princess := readInt()
dragon := readInt()
t := readInt()
f := readInt()
c := readInt()

// If the number of dragons is less than or equal to the number of princesses, print 0 and exit
if dragon <= princess {
    fmt.Println(0)
    os.Exit(0)
}

// Initialize the result counter for the number of iterations
result := 0

// Calculate the initial position based on the time and number of princesses
position := t * princess

// Update the position based on the ratio of princesses to dragons
position += princess * position / (dragon - princess)

// Loop until the position is less than the target value 'c'
for position < c {
    // Increment the result counter for each iteration
    result += 1
    
    // Update the position based on the current number of princesses and dragons
    position += princess * position / dragon
    
    // Add the effect of the time factor 'f' to the position
    position += princess * f
    
    // Recalculate the position based on the updated values
    position += princess * position / (dragon - princess)
}

// Print the final result which is the number of iterations needed
fmt.Println(result)

