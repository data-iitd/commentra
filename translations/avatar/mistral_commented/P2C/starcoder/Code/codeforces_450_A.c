#######
# Code
#######

# Define the number of elements 'n' and the modulus'm' in the list 'l'
scanf("%d %d", &n, &m);

// Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by'm'
int l2[n];

// Iterate through each element 'i' in the list 'l'
for (int i = 0; i < n; i++) {
    // Check if the element 'i' is divisible by'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
    if (l[i] % m == 0) {
        l2[i] = l[i] / m;
    } else {
        l2[i] = (int) (l[i] / m + 1);
    }
}

// Find the maximum quotient in 'l2'
int mx = 0;
for (int i = 0; i < n; i++) {
    if (l2[i] > mx) {
        mx = l2[i];
    }
}

// Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
int ind = -1;
for (int i = 0; i < n; i++) {
    // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
    if (l2[i] == mx) {
        ind = i;
    }
}

// Print the index 'ind' plus one (since the indices in C start from 0)
printf("%d", ind + 1);

