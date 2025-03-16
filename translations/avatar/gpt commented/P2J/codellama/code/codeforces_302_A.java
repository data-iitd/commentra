// Read two integers n and m from input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Count the number of '-' characters in the input string
int sa = 0;
String s = sc.next();
for (int i = 0; i < s.length(); i++) {
    if (s.charAt(i) == '-') {
        sa++;
    }
}

// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
sa = Math.min(n - sa, sa);

// Initialize an empty list to store results
ArrayList<String> ss = new ArrayList<>();

// Loop m times to read pairs of integers a and b
for (int i = 0; i < m; i++) {
    // Read two integers a and b from input
    int a = sc.nextInt();
    int b = sc.nextInt();
    
    // Calculate the difference b - a
    b -= a;
    
    // Check if b is odd and less than or equal to double the count of '-'
    // Append "1\n" to the results if true, otherwise append "0\n"
    ss.add((b % 2 == 0 && b <= sa << 1) ? "1\n" : "0\n");
}

// Print the concatenated results from the list
for (String s : ss) {
    System.out.print(s);
}

