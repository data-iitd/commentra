#######
# Code
#######

# Define input variables
N, K = scanf("%d %d", &N, &K);
char S[N+1];
scanf("%s", S);

// Initialize a flag variable
int aaaa = 0;

// Check if K is greater than or equal to 15
if (K >= 15) {
    // If so, set the flag variable to True
    aaaa = 1;
}

// Else, check if 2^K is greater than or equal to N
else if (2 ^ K >= N) {
    // If so, set the flag variable to True
    aaaa = 1;
}

// If the flag variable is True, print the result and exit the function
if (aaaa) {
    printf("%d", min(S)*N);
    return 0;
}

// Define a function to get the last dictionary of the string S
char* get_last_dict(char* s_str) {
    // Create a new string U by concatenating S with its reverse
    char U[N*2+1];
    strcpy(U, s_str);
    strcat(U, s_str);
    strrev(U);
    // Find the minimum character in S
    char c = min(s_str);
    // Find the index of the first occurrence of the minimum character in U
    int p = strchr(U, c) - U;
    // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
    int minindex = p;
    // Move the pointer p to the next character in U
    p += 1;
    // Check if the substring starting from the current pointer and of length N is a normal dictionary
    while (p <= N) {
        // If the character at the current pointer in U is the same as the minimum character,
        // and if the substring starting from the current pointer and of length N is a normal dictionary,
        // update the index minindex
        if (U[p] == c && check_normal_dict(U, minindex, p)) {
            minindex = p;
        }
        // Move the pointer p to the next character in U
        p += 1;
    }
    // Return the substring starting from minindex and of length N
    return U + minindex;
}

// Define a function to check if a substring is a normal dictionary
int check_normal_dict(char* u, int pointer1, int pointer2) {
    // Iterate through each character in the substring of length N
    for (int i = 0; i < N; i++) {
        // If the character at pointer1+i in U is greater than the character at pointer2+i,
        // return True (indicating that the substring is a normal dictionary)
        if (u[pointer1+i] > u[pointer2+i]) {
            return 1;
        }
        // Else, if the character at pointer1+i is less than the character at pointer2+i,
        // return False (indicating that the substring is not a normal dictionary)
        else if (u[pointer1+i] < u[pointer2+i]) {
            return 0;
        }
    }
    // If none of the above conditions are met, return False
    return 0;
}

// Get the last dictionary of the string S
char* S = get_last_dict(S);

// If K is equal to 1, print the string S
if (K == 1) {
    printf("%s", S);
}
// Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
else {
    int count = 0;
    for (int i = 0; i < N; i++) {
        // If the current character is the same as the first character, increment the count
        if (S[i] == S[0]) {
            count++;
        }
        // Else, break the loop
        else {
            break;
        }
    }
    // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
    if (count * (2 ^ (K - 1)) >= N) {
        printf("%s", S[0]*N);
    }
    // Else, construct the string S by concatenating N-1 instances of the first character with the original string S
    else {
        char S_new[N+1];
        strcpy(S_new, S[0]*(count * (2 ^ (K - 1)) - 1));
        strcat(S_new, S);
        // Print the first N characters of the constructed string S
        printf("%s", S_new);
    }
}

