#######
# Code
#######

// Define input variables
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
int K = scanner.nextInt();
String S = scanner.next();

// Initialize a flag variable
boolean aaaa = false;

// Check if K is greater than or equal to 15
if (K >= 15) {
    // If so, set the flag variable to True
    aaaa = true;
}

// Else, check if 2^K is greater than or equal to N
else if (Math.pow(2, K) >= N) {
    // If so, set the flag variable to True
    aaaa = true;
}

// If the flag variable is True, print the result and exit the function
if (aaaa) {
    System.out.println(S.length() * N);
    return;
}

// Define a function to get the last dictionary of the string S
String get_last_dict(String s_str) {
    // Create a new string U by concatenating S with its reverse
    String U = s_str + new StringBuilder(s_str).reverse();
    // Find the minimum character in S
    char c = s_str.charAt(0);
    // Find the index of the first occurrence of the minimum character in U
    int p = U.indexOf(c);
    // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
    int minindex = p;
    // Move the pointer p to the next character in U
    p += 1;
    // Check if the substring starting from the current pointer and of length N is a normal dictionary
    while (p <= N) {
        // If the character at the current pointer in U is the same as the minimum character,
        // and if the substring starting from the current pointer and of length N is a normal dictionary,
        // update the index minindex
        if (U.charAt(p) == c && check_normal_dict(U, minindex, p)) {
            minindex = p;
        }
        // Move the pointer p to the next character in U
        p += 1;
    }
    // Return the substring starting from minindex and of length N
    return U.substring(minindex, minindex + N);
}

// Define a function to check if a substring is a normal dictionary
boolean check_normal_dict(String u, int pointer1, int pointer2) {
    // Iterate through each character in the substring of length N
    for (int i = 0; i < N; i++) {
        // If the character at pointer1+i in U is greater than the character at pointer2+i,
        // return True (indicating that the substring is a normal dictionary)
        if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
            return true;
        }
        // Else, if the character at pointer1+i is less than the character at pointer2+i,
        // return False (indicating that the substring is not a normal dictionary)
        else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
            return false;
        }
    }
    // If none of the above conditions are met, return False
    return false;
}

// Get the last dictionary of the string S
String S = get_last_dict(S);

// If K is equal to 1, print the string S
if (K == 1) {
    System.out.println(S);
}
// Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
else {
    int count = 0;
    for (char c : S.toCharArray()) {
        // If the current character is the same as the first character, increment the count
        if (c == S.charAt(0)) {
            count++;
        }
        // Else, break the loop
        else {
            break;
        }
    }
    // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
    if (count * (int) Math.pow(2, K - 1) >= N) {
        System.out.println(S.charAt(0) * N);
    }
    // Else, construct the string S by concatenating N-1 instances of the first character with the original string S
    else {
        S = S.charAt(0) * (count * (int) Math.pow(2, K - 1) - 1) + S;
        // Print the first N characters of the constructed string S
        System.out.println(S.substring(0, N));
}

