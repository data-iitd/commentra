#######
# Code
#######

# Define input variables N and M as integers
scanf("%d %d", &N, &M);

// Comments: Get the dimensions N and M of the matrices S and T from user input

// Initialize variables S and T as strings
char S[N], T[M];
scanf("%s", S);
scanf("%s", T);

// Convert strings S and T into lists
char list_S[N], list_T[M];
for (int i = 0; i < N; i++) {
    list_S[i] = S[i];
}
for (int i = 0; i < M; i++) {
    list_T[i] = T[i];
}

// Initialize a list Number_i containing numbers from 0 to N-1
int Number_i[N];
for (int i = 0; i < N; i++) {
    Number_i[i] = i;
}

// Initialize an empty list Number_iMN to store the results of the division i*M/N
int Number_iMN[N];

// Iterate through each number i in the list Number_i
for (int i = 0; i < N; i++) {
    // Append the result of the division i*M/N to the list Number_iMN
    Number_iMN[i] = i * M / N;
}

// Initialize a list Number_j containing numbers from 0 to M-1
int Number_j[M];
for (int i = 0; i < M; i++) {
    Number_j[i] = i;
}

// Find the common elements between Number_iMN and Number_j using set intersection
int Kaburi_j[M];
for (int i = 0; i < M; i++) {
    Kaburi_j[i] = Number_j[i];
}

// Initialize an empty list Kaburi_i to store the integer representations of the common elements
int Kaburi_i[M];

// Iterate through each common element j in Kaburi_j
for (int i = 0; i < M; i++) {
    // Append the integer representation of j to the list Kaburi_i
    Kaburi_i[i] = Number_iMN[i];
}

// Initialize a counter variable to keep track of the current index in Kaburi_i
int counter = 0;

// Initialize a flag variable to indicate whether there is a mismatch between S and T
int Flag = 0;

// Determine the size of Kaburi_i
int Kaburi_Size = M;

// Iterate through each index in Kaburi_i until the end of the list
while (counter <= Kaburi_Size - 1) {
    // Check if the corresponding elements in S and T match
    if (list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]]) {
        // Set the flag variable to 1 if there is a mismatch
        Flag = 1;
        // Break out of the loop
        break;
    }
    // Increment the counter variable
    counter++;
}

// Define a function gcd(a, b) to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    // While b is not equal to 0, keep updating a and b using the modulo operator
    while (b > 0) {
        a = b;
        b = a % b;
    }
    // Return the final value of a as the greatest common divisor
    return a;
}

// Check if there is a mismatch between S and T
if (Flag == 1) {
    // Print -1 if there is a mismatch
    printf("-1");
} else {
    // Calculate and print the product of N and M divided by their greatest common divisor
    printf("%d", N * M / gcd(N, M));
}

