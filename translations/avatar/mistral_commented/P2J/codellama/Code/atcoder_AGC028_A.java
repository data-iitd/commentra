#######
# Code
#######

// Define input variables N and M as integers
int N, M;

// Comments: Get the dimensions N and M of the matrices S and T from user input

// Initialize variables S and T as strings
String S, T;

// Convert strings S and T into lists
List<Character> list_S = new ArrayList<Character>();
List<Character> list_T = new ArrayList<Character>();

// Initialize a list Number_i containing numbers from 0 to N-1
List<Integer> Number_i = new ArrayList<Integer>();

// Initialize an empty list Number_iMN to store the results of the division i*M/N
List<Integer> Number_iMN = new ArrayList<Integer>();

// Iterate through each number i in the list Number_i
for (int i = 0; i < N; i++) {
    // Append the result of the division i*M/N to the list Number_iMN
    Number_iMN.add(i * M / N);
}

// Initialize a list Number_j containing numbers from 0 to M-1
List<Integer> Number_j = new ArrayList<Integer>();

// Find the common elements between Number_iMN and Number_j using set intersection
List<Integer> Kaburi_j = new ArrayList<Integer>();

// Initialize an empty list Kaburi_i to store the integer representations of the common elements
List<Integer> Kaburi_i = new ArrayList<Integer>();

// Iterate through each common element j in Kaburi_j
for (int j = 0; j < M; j++) {
    // Append the integer representation of j to the list Kaburi_i
    Kaburi_i.add(j * N / M);
}

// Initialize a counter variable to keep track of the current index in Kaburi_i
int counter = 0;

// Initialize a flag variable to indicate whether there is a mismatch between S and T
int Flag = 0;

// Determine the size of Kaburi_i
int Kaburi_Size = Kaburi_i.size();

// Iterate through each index in Kaburi_i until the end of the list
while (counter < Kaburi_Size) {
    // Check if the corresponding elements in S and T match
    if (S.charAt(Kaburi_i.get(counter)) != T.charAt(Kaburi_j.get(counter))) {
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
    System.out.println(-1);
} else {
    // Calculate and print the product of N and M divided by their greatest common divisor
    System.out.println(N * M / gcd(N, M));
}

