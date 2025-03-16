
// Read input values for N and K
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int K = sc.nextInt();

// Read the string S
String S = sc.next();

// Initialize a flag to determine if we can use a shortcut for output
boolean aaaa = false;

// Check if K is large enough or if 2^K is greater than or equal to N
if (K >= 15) {
    aaaa = true;
} else if (Math.pow(2, K) >= N) {
    aaaa = true;
}

// If the shortcut condition is met, print the minimum character repeated N times and exit
if (aaaa) {
    System.out.println(min(S) * N);
    System.exit(0);
}

// Function to get the lexicographically smallest rotation of the string
public static String get_last_dict(String s_str) {
    // Create a doubled string to facilitate rotation comparison
    String U = s_str + new StringBuilder(s_str).reverse().toString();
    // Find the minimum character in the original string
    char c = min(s_str);
    // Get the first occurrence of the minimum character
    int p = U.indexOf(c);
    int minindex = p;
    p += 1;
    
    // Iterate through the doubled string to find the smallest rotation
    while (p <= N) {
        if (U.charAt(p) == c) {
            // Compare the current rotation with the previously found minimum
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p += 1;
    }
    
    // Return the smallest rotation of length N
    return U.substring(minindex, minindex + N);
}

// Function to compare two rotations of the string
public static boolean check_normal_dict(String u, int pointer1, int pointer2) {
    // Compare characters of the two rotations
    for (int i = 0; i < N; i++) {
        if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
            return true;
        } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
            return false;
        }
    }
    return false;
}

// Get the lexicographically smallest rotation of S
S = get_last_dict(S);

// If K is 1, simply print the smallest rotation
if (K == 1) {
    System.out.println(S);
} else {
    int count = 0;
    // Count how many times the first character appears consecutively
    for (int i = 0; i < S.length(); i++) {
        if (S.charAt(i) == S.charAt(0)) {
            count += 1;
        } else {
            break;
        }
    }
    
    // Check if the repeated character can fill the string of length N
    if (count * (int) Math.pow(2, (K - 1)) >= N) {
        System.out.println(S.charAt(0) * N);
    } else {
        // Construct the output string based on the count and the original string
        S = S.charAt(0) * (count * ((int) Math.pow(2, (K - 1)) - 1)) + S;
        // Print the first N characters of the constructed string
        System.out.println(S.substring(0, N));
    }
}

