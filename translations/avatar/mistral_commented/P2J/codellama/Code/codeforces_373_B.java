// Function to calculate the sum of digits in a number
public static int sum(int k) {
    // Initialize the sum to zero
    int ret = 0;
    // Base value for power of ten
    int pw = 10;
    // Initialize the length of the number to 1
    int len = 1;

    // Continue the loop until the power of ten is less than or equal to the number
    while (true) {
        // Calculate the current digit
        int cur = Math.min(pw - 1, k);
        // Calculate the previous power of ten
        int prev = pw / 10;
        // Add the number of digits in the current power of ten to the sum
        ret += (cur - prev + 1) * len;
        // If the power of ten is greater than the number, break the loop
        if (pw - 1 >= k) {
            break;
        }
        // Increment the length of the number
        len += 1;
        // Multiply the power of ten by 10
        pw *= 10;
    }

    // Return the sum of digits in the number
    return ret;
}

// Take input of w, m, and k
Scanner sc = new Scanner(System.in);
int w = sc.nextInt();
int m = sc.nextInt();
int k = sc.nextInt();

// Initialize the lower bound to 0
int lo = 0;
// Initialize the upper bound to a very large number
int hi = (int) 1e18;

// Binary search to find the middle value
while (hi - lo > 1) {
    // Calculate the middle value
    int md = (lo + hi) / 2;
    // Calculate the sum of digits in the range [m, m+md] and subtract the sum of digits in the range [m-1, m]
    int c = sum(m + md - 1) - sum(m - 1);
    // If the product of the count and k is less than or equal to w, update the lower bound
    if (c * k <= w) {
        lo = md;
    }
    // Otherwise, update the upper bound
    else {
        hi = md;
    }
}

// Print the result
System.out.println(lo);

