
// Import necessary libraries and modules
import java.util.*;
import java.io.*;

// Define constants and global variables
int N = scanner.nextInt();  // Number of inputs
String[] S = new String[N];  // Array to store the inputs as strings
String[] march = {"M", "A", "R", "C", "H"};  // Array of marching orders
int[] march_lis = new int[5];  // Array to store the count of each marching order
int ans = 0;  // Variable to store the answer

// atcoder_ABC089_C logic of the code
// Initialize march_lis with zeros
Arrays.fill(march_lis, 0);
// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for (int i = 0; i < N; i++) {
    S[i] = scanner.next().trim();
    if (Arrays.asList(march).contains(S[i].substring(0, 1).toUpperCase())) {
        march_lis[Arrays.asList(march).indexOf(S[i].substring(0, 1).toUpperCase())] += 1;
    }
}
// Calculate the answer by finding the triple product of the counts of each marching order
for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
        for (int k = j + 1; k < 5; k++) {
            ans += march_lis[i] * march_lis[j] * march_lis[k];
        }
    }
}
// Print the answer
System.out.println(ans);

