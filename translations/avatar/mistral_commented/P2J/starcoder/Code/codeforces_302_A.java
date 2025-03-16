// Define the number of strings n and the number of operations m
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Calculate the number of '-' symbols in the input string
int sa = 0;
for (int i = 0; i < n; i++) {
    if (sc.next().charAt(0) == '-') {
        sa++;
    }
}

// Ensure the number of '-' symbols is valid
sa = Math.min(n - sa, sa);

// Initialize an empty list'ss' to store the results of each operation
List<String> ss = new ArrayList<>();

// Perform each operation as described in the problem statement
for (int i = 0; i < m; i++) {
    // Read two integers a and b from the input
    int a = sc.nextInt();
    int b = sc.nextInt();

    // Calculate the difference between b and a
    b -= a;

    // Check if the difference is valid based on the number of '-' symbols
    if (b % 2 == 0 || b > sa << 1) {
        // If the difference is valid, add '1' to the result list'ss'
        ss.add("1\n");
    } else {
        // If the difference is not valid, add '0' to the result list'ss'
        ss.add("0\n");
    }
}

// Print the final result by joining all the strings in the'ss' list with an empty string as separator
System.out.print(String.join("", ss));

