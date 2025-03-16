// Take an integer input from the user
Scanner sc = new Scanner(System.in);
int y = sc.nextInt();

// Take a list of integers as input from the user
int n = sc.nextInt();
int[] arr = new int[n];
for (int i = 0; i < n; i++) {
    arr[i] = sc.nextInt();
}

// Iterate through each index 'i' in the list 'arr'
for (int i = 0; i < n; i++) {
    // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
    for (int j = i + 1; j < n; j++) {
        // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
        for (int k = 0; k < n; k++) {
            // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
            if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                System.out.println(k + 1 + " " + j + 1 + " " + i + 1);
                return;
            }
        }
    }
}

// If no such indices are found, print -1
System.out.println(-1);

