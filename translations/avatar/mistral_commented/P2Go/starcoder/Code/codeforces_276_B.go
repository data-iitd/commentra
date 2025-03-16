// Initialize an empty list's' to store input elements
s := []rune(input())

// Initialize an empty map 'dt' to store the count of each unique element
dt := make(map[rune]int)

// Set a boolean variable 'x' to True to indicate whether there is an odd count element in the list
x := true

// Iterate through each element 'i' in the list's'
for _, i := range s {
    // Check if the element 'i' already exists as a key in the map 'dt'
    if _, ok := dt[i]; ok {
        // If it does, increment its value by 1
        dt[i]++
    } else {
        // If not, add it as a new key with a value of 1
        dt[i] = 1
    }
}

// Initialize a counter 'cnt' to 0 and set 'x' to True
cnt := 0
x = true

// Iterate through each key-value pair ('key', 'value') in the map 'dt'
for key, value := range dt {
    // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
    if value%2!= 0 && cnt < 1 {
        cnt++
    }
    // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to False and break the loop
    if value%2!= 0 && cnt >= 1 {
        x = false
        break
    }
}

// After the loop, check the value of 'x'
if x {
    // If it is True, print "First"
    fmt.Println("First")
} else if!x && len(s)%2 == 0 {
    // If it is False and the length of the list's' is even, print "Second"
    fmt.Println("Second")
} else if!x && len(s)%2!= 0 {
    // If it is False and the length of the list's' is odd, print "First"
    fmt.Println("First")
}

