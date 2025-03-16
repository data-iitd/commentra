
// Function to compute the Greatest Common Divisor (GCD) of two numbers
public static int G(int a, int b) {
    // Continue looping until b becomes 0
    while (a % b!= 0) {
        // Update a and b using the Euclidean algorithm
        a = b;
        b = a % b;
    }
    // Return the GCD
    return b;
}

// Function to compute the Least Common Multiple (LCM) of two numbers
public static int L(int a, int b) {
    // Calculate LCM using the relationship between GCD and LCM
    return a * b / G(a, b);
}

// Read input values and split them into an array
String[] l = in.nextLine().split(" ");

// Convert the input strings to integers
int x = Integer.parseInt(l[0]);
int y = Integer.parseInt(l[1]);
int a = Integer.parseInt(l[2]);
int b = Integer.parseInt(l[3]);

// Calculate the LCM of x and y
int lcm = L(x, y);

// Calculate and print the count of multiples of LCM in the range [a, b]
System.out.println(b / lcm - (a - 1) / lcm);

