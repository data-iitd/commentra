
// Define a helper function 'twos_in_factorial' to count the number of twos in the factorial of a given number
public static int twos_in_factorial(int n) {
    // Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
    return n - Integer.bitCount(n);
}

// Define a helper function 'parity_of_nCr' to check if the index 'i' has odd parity in the combination 'nCr'
public static boolean parity_of_nCr(int n, int i) {
    // Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
    int f = twos_in_factorial;
    // Return true if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
    return f(n) - f(n - i) - f(i) > 0;
}

// Check if the input is valid and process the given problem
public static void main(String[] args) throws IOException {
    // Read the input values from the standard input
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    String[] numsStr = br.readLine().strip().split(" ");
    int[] nums = new int[numsStr.length];
    for (int i = 0; i < numsStr.length; i++) {
        nums[i] = Integer.parseInt(numsStr[i]) - 1;
    }
    
    // Initialize a flag to indicate if there is no '1' in the list of numbers
    boolean noOne = true;
    
    // If there is no '1' in the list of numbers, then replace each number by half of it
    for (int num : nums) {
        if (num!= 0) {
            noOne = false;
            break;
        }
    }
    if (noOne) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] /= 2;
        }
    }
    
    // Initialize a flag to indicate if the result is odd
    boolean isOdd = false;
    
    // Iterate through each number in the list and check if it satisfies the given condition
    for (int i = 0; i < nums.length; i++) {
        // Skip the number if it doesn't satisfy the parity condition
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)!= 0) {
            // Toggle the 'isOdd' flag
            isOdd =!isOdd;
        }
    }
    
    // Print the result based on the value of the 'isOdd' flag
    if (!isOdd) {
        System.out.println(0);
    } else {
        // If there is no '1' in the list of numbers, then print the result with the 'noOne' flag shifted to the left
        System.out.println(1 << (noOne? 1 : 0));
    }
}

