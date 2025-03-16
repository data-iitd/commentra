
// Function to find the greatest common divisor (GCD) of two numbers using Euclidean algorithm
public static int G(int a, int b) {
    // Continue the loop until the remainder is zero
    while (a % b!= 0) {
        // Swap a and b, and update a with the new value of b
        a = b;
        b = a % b;
    }
    // Return the greatest common divisor (GCD)
    return b;
}

// Function to find the least common multiple (LCM) of two numbers
public static int L(int a, int b) {
    // Find the GCD of a and b using the G function
    int gcd = G(a, b);
    // Return the product of a and b divided by their GCD
    return a * b / gcd;
}

// Read input as a list of strings, split it by spaces and convert each element to an integer
Scanner sc = new Scanner(System.in);
String[] l = sc.nextLine().split(" ");
int x = Integer.parseInt(l[0]);
int y = Integer.parseInt(l[1]);
int a = Integer.parseInt(l[2]);
int b = Integer.parseInt(l[3]);

// Find the least common multiple (LCM) of x and y using the L function
int lcm = L(x, y);

// Calculate the result by subtracting (a-1) from b divided by lcm
System.out.println(b / lcm - (a - 1) / lcm);

