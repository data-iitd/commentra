// Define a lambda function to read multiple integers from input
Function<String, Integer[]> R = (x) -> Arrays.stream(x.split(" ")).map(Integer::parseInt).toArray(Integer[]::new);

// Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
int n = R()[0], m = R()[1], s = R()[2], f = R()[3];

// Determine the direction of movement based on the starting and finishing positions
int d = 1;  // Move right
if (s < f) {
    d = -1;  // Move left
}

// Initialize the result string to store the path taken
String res = "";

// Initialize the step counter and current position
int i = 1, j = s;

// Read the first obstacle's position and range
int t = R()[0], l = R()[1], r = R()[2];
int k = 1;  // Counter for the number of obstacles processed

// Loop until the current position reaches the finishing position
while (j!= f) {
    // Check if we need to read a new obstacle's position and range
    if (i > t && k < m) {
        t = R()[0];  // Read the next obstacle's position and range
        l = R()[1];
        r = R()[2];
        k += 1;  // Increment the obstacle counter
    }

    // Check if the current position is at an obstacle
    if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
        res += 'X';  // Mark the position with 'X' if it's blocked by an obstacle
    } else {
        res += (d == 1)? 'R' : 'L';  // Append the direction character to the result
        j += d;  // Move to the next position in the determined direction
    }

    i += 1;  // Increment the step counter
}

// Print the resulting path taken
System.out.println(res);

