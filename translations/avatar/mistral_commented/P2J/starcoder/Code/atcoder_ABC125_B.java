// Read the number of test cases
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Read the array V of size N
String[] V = new String[N];
for (int i = 0; i < N; i++) {
    V[i] = sc.next();
}

// Read the array C of size N
String[] C = new String[N];
for (int i = 0; i < N; i++) {
    C[i] = sc.next();
}

// Initialize an empty list to store the differences between V and C
List<Integer> list = new ArrayList<>();

// Initialize variables to store the current difference and the sum of differences
int ans = 0;
int X = 0;
int Y = 0;

// Iterate through each index i from 0 to N-1
for (int i = 0; i < N; i++) {
    // If the difference between V[i] and C[i] is positive
    if (Integer.parseInt(V[i]) - Integer.parseInt(C[i]) > 0) {
        // Update X and Y with the respective values from V and C at index i
        X = Integer.parseInt(V[i]);
        Y = Integer.parseInt(C[i]);
        // Append the difference X-Y to the list
        list.add(X - Y);
        // Update the sum of differences
        ans += X - Y;
    }
}

// Print the sum of all the elements in the list
System.out.println(list.stream().mapToInt(i -> i).sum());
// Print the sum of all the differences between V and C
System.out.println(ans);

