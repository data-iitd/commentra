// Disable synchronization with C I/O for faster input/output
// cin.tie(0);
// ios::sync_with_stdio(false);

// Initialize a vector to hold the denominations of money
// vector<int> m;
// m.push_back(10);   // Add 10
// m.push_back(50);   // Add 50
// m.push_back(100);  // Add 100
// m.push_back(500);  // Add 500

// Read money input until EOF or invalid input
// for(int money; cin >> money, money;) {
//     // Print a newline before the output of subsequent transactions
//     if(!first)
//         cout << endl;

//     first = false; // Set the flag to false after the first input
//     int sum = 0; // Initialize sum to calculate total value of coins
//     vector<int> num(4); // Vector to hold the number of each denomination

//     // Read the number of coins for each denomination and calculate the total sum
//     for(int i = 0; i < 4; ++i) {
//         cin >> num[i]; // Input the number of coins for the current denomination
//         sum += num[i] * m[i]; // Update the total sum
//     }

//     // Calculate the change to be returned
//     int change = sum - money;

//     // Calculate how many coins of each denomination to return as change
//     for(int i = 3; i >= 0; --i) {
//         if(change / m[i]) { // Check if the current denomination can be used for change
//             num[i] = num[i] - change / m[i]; // Reduce the number of coins of this denomination
//             change %= m[i]; // Update the remaining change to be returned
//         }
//     }

//     // Output the remaining coins of each denomination that are greater than zero
//     for(int i = 0; i < 4; ++i)
//         if(num[i] > 0) // Only print denominations that still have coins left
//             cout << m[i] << " " << num[i] << endl; // Print denomination and count
// }

// return EXIT_SUCCESS; // Return success status

