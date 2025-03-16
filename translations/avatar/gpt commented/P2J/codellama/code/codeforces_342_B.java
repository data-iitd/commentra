// Define a lambda function to read multiple integers from input
R = () -> Arrays.stream(new Scanner(System.in).nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

// Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
int[] nmfs = R();
int n = nmfs[0], m = nmfs[1], s = nmfs[2], f = nmfs[3];

// Determine the direction of movement based on the starting and finishing positions
int d = s < f ? 1 : -1;  // Move right
char c = s < f ? 'R' : 'L';  // Character representing right movement

// Initialize the result string to store the path taken
String res = "";

// Initialize the step counter and current position
int i = 1, j = s;

// Read the first obstacle's position and range
int[] tlr = R();
int t = tlr[0], l = tlr[1], r = tlr[2], k = 1;  // Counter for the number of obstacles processed

// Loop until the current position reaches the finishing position
while (j != f) {
    // Check if we need to read a new obstacle's position and range
    if (i > t && k < m) {
        tlr = R();  // Read the next obstacle's position and range
        t = tlr[0];
        l = tlr[1];
        r = tlr[2];
        k++;  // Increment the obstacle counter
    }

    // Check if the current position is at an obstacle
    if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
        res += "X";  // Mark the position with 'X' if it's blocked by an obstacle
    } else {
        res += c;  // Append the direction character to the result
        j += d;  // Move to the next position in the determined direction
    }

    i++;  // Increment the step counter
}

// Print the resulting path taken
System.out.println(res);

