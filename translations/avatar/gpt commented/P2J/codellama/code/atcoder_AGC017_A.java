
// Read two integers N and P from input
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int P = sc.nextInt();

// Function to calculate combinations C(N, K)
int combi(int N, int K) {
    int a = 1;
    // Calculate the numerator of the combination formula
    for (int i = 0; i < K; i++) {
        a *= N - i;
    }
    // Calculate the denominator of the combination formula
    for (int j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

// Initialize the answer variable
int ans = 0;

// Read a list of integers from input
int[] lis = new int[N];
for (int i = 0; i < N; i++) {
    lis[i] = sc.nextInt();
}

// Create a list to hold the parity (0 or 1) of each number
int[] ls = new int[N];
for (int a : lis) {
    // Append the remainder when divided by 2 (0 for even, 1 for odd)
    ls[i] = a % 2;
}

// Count the number of 1s (odd numbers) and 0s (even numbers) in the list
int one = 0;
int zero = 0;
for (int a : ls) {
    if (a == 1) {
        one++;
    } else {
        zero++;
    }
}

// Initialize variables to count patterns
int pattern_a = 0;
int pattern_b = 0;

// Calculate the total number of patterns for the even numbers
for (int j = 0; j <= zero; j++) {
    pattern_b += combi(zero, j);
}

// Initialize a variable to track the number of odd numbers used
int time = 0;

// Loop through all possible counts of odd numbers used
while (time <= one) {
    // Check if the current count of odd numbers is congruent to P modulo 2
    if (time % 2 == P) {
        // If it is, add the number of combinations to pattern_a
        pattern_a += combi(one, time);
    }
    time++;
}

// Print the final result, which is the product of pattern_a and pattern_b
System.out.println(pattern_a * pattern_b);

