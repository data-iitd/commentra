#######
# Code
#######

# Define input variables
int n, L, R, QL, QR;
cin >> n >> L >> R >> QL >> QR;
// Read input as a list of integers
vector<int> W(n);
for (int i = 0; i < n; i++) {
    cin >> W[i];
}

// Initialize empty list to store sum of elements
vector<int> sum_el(n+1);

// Calculate sum of elements from 1 to n
for (int i = 1; i <= n; i++) {
    // Add current element and previous sum to get sum of current element
    sum_el[i] = W[i-1] + sum_el[i-1];
}

// Calculate answer
int answer = QR * (n - 1) + sum_el[n] * R;

// Iterate through all elements to find minimum energy
for (int i = 1; i <= n; i++) {
    // Calculate energy for current index
    int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);
    
    // Check if current index is greater than its mirror index
    if (i > (n - i)) {
        // If true, add energy of segments between current index and its mirror index
        energy += (i - (n - i) - 1) * QL;
    }

    // Check if mirror index is greater than current index
    else if ((n - i) > i) {
        // If true, add energy of segments between mirror index and current index
        energy += ((n - i) - i - 1) * QR;
    }

    // Update answer if current energy is less than previous answer
    if (energy < answer) {
        answer = energy;
    }
}

// Print the answer
cout << answer << endl;

