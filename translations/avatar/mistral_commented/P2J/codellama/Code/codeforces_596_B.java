// Ask the user for the number of elements in the list
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Ask the user to input the elements of the list separated by spaces
int[] r = new int[n];
for (int i = 0; i < n; i++) {
    r[i] = sc.nextInt();
}

// Initialize a variable to store the answer
int ans = Math.abs(r[0]);

// Use a for loop to calculate the sum of the absolute differences between consecutive elements
for (int i = 1; i < n; i++) {
    ans += Math.abs(r[i] - r[i-1]);
}

// Print the final answer
System.out.println(ans);

