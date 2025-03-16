// Read the input string from the user
String soz = sc.nextLine();

// Initialize a list 'a' to store the cumulative count of consecutive characters
// The length of 'a' is one more than the length of 'soz' to handle the base case
int[] a = new int[soz.length() + 1];

// Iterate through the string to fill the cumulative count array 'a'
for (int i = 1; i < soz.length(); i++) {
    // Carry forward the previous count
    a[i] = a[i - 1];
    
    // If the current character is the same as the previous one, increment the count
    if (soz.charAt(i - 1) == soz.charAt(i)) {
        a[i] += 1;
    }
}

// Read the number of queries from the user
int n = sc.nextInt();

// Initialize an empty list to store the results of each query
ArrayList<Integer> arr = new ArrayList<>();

// Process each query
for (int i = 0; i < n; i++) {
    // Read the start and end indices for the query
    int m = sc.nextInt();
    int l = sc.nextInt();
    
    // Calculate the number of consecutive characters between indices m and l
    // and append the result to the 'arr' list
    arr.add(a[l - 1] - a[m - 1]);
}

// Print the results for each query
for (int i : arr) {
    System.out.println(i);
}

