// Read two integers n and m from input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Count the number of '-' characters in the input string
int sa = 0;
for (int i = 0; i < n; i++) {
    if (sc.next().charAt(0) == '-') {
        sa++;
    }
}

// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
int min = Math.min(n - sa, sa);

// Initialize an empty list to store results
List<String> ss = new ArrayList<>();

// Loop m times to read pairs of integers a and b
for (int i = 0; i < m; i++) {
    // Read two integers a and b from input
    int a = sc.nextInt();
    int b = sc.nextInt();
    
    // Calculate the difference b - a
    b -= a;
    
    // Check if b is odd and less than or equal to double the count of '-'
    // Append "1\n" to the results if true, otherwise append "0\n"
    ss.add((b % 2 == 1 && b <= min << 1)? "1\n" : "0\n");
}

// Print the concatenated results from the list
System.out.print(String.join("", ss));

