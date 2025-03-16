package main  // Step 1: Declare the main package.

import (  // Step 2: Import the necessary packages.
    "fmt"  // Import the fmt package for formatted I/O.
)

func main() {  // Step 3: Define the main function which is the entry point of the program.
    var sheep, wolf int  // Step 4: Declare two integer variables, sheep and wolf.

    fmt.Scanf("%d %d", &sheep, &wolf)  // Step 5: Use Scanf to read the number of sheep and wolves from the user.

    if wolf >= sheep {  // Step 6: Check if the number of wolves is greater than or equal to the number of sheep.
        fmt.Println("unsafe")  // Step 7: If the condition is true, print "unsafe".
    } else {
        fmt.Println("safe")  // Step 8: Otherwise, print "safe".
    }
}  // Step 9: End of the main function.

