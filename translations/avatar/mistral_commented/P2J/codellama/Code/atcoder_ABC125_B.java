
// Read the number of test cases
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Read the array V of size N
int[] V = new int[N];
for (int i = 0; i < N; i++) {
    V[i] = sc.nextInt();
}

// Read the array C of size N
int[] C = new int[N];
for (int i = 0; i < N; i++) {
    C[i] = sc.nextInt();
}

// Initialize an empty list to store the differences between V and C
ArrayList<Integer> list = new ArrayList<>();

// Initialize variables to store the current difference and the sum of differences
int ans = 0;
int X = 0;
int Y = 0;

// Iterate through each index i from 0 to N-1
for (int i = 0; i < N; i++) {
    // If the difference between V[i] and C[i] is positive
    if (V[i] - C[i] > 0) {
        // Update X and Y with the respective values from V and C at index i
        X = V[i];
        Y = C[i];
        // Append the difference X-Y to the list
        list.add(X - Y);
        // Update the sum of differences
        ans += X - Y;
    }
}

// Print the sum of all the elements in the list
System.out.println(list.stream().mapToInt(Integer::intValue).sum());
// Print the sum of all the differences between V and C
System.out.println(ans);

