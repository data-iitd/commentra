// Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
ABC := tuple(map(int, strings.Split(fmt.Sprintf("%v", input()), " ")))

// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
if strings.Count(fmt.Sprintf("%v", ABC), "5") == 2 {
    // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
    fmt.Printf("YES\n" if sum(ABC) == 17 else "NO\n")
} else {
    // If the condition is not met, print 'NO'
    fmt.Println("NO")
}

