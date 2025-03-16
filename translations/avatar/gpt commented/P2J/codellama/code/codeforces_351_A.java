// Read an integer input for the number of elements
int n = sc.nextInt();

// Read a line of space-separated floats and convert them to a list of floats
List<Float> arr = new ArrayList<>();
for (int i = 0; i < n; i++) {
    arr.add(sc.nextFloat());
}

// Calculate the fractional parts of the elements, excluding whole numbers
List<Float> arr_frac = new ArrayList<>();
for (int i = 0; i < n; i++) {
    if (arr.get(i) - (int) arr.get(i) != 0) {
        arr_frac.add(arr.get(i) - (int) arr.get(i));
    }
}

// Calculate the number of whole numbers that can be added to the fractional parts
int o = 2 * n - arr_frac.size();

// Calculate the sum of the fractional parts
float arr_sum = 0;
for (int i = 0; i < arr_frac.size(); i++) {
    arr_sum += arr_frac.get(i);
}

// Initialize the result with a large number
float res = 1e9;

// Iterate through possible counts of fractional parts used
for (int i = 0; i <= n; i++) {
    // Check if the current count of fractional parts plus whole numbers is sufficient
    if (i + o >= n) {
        // Update the result with the minimum difference found
        res = Math.min(res, Math.abs(i - arr_sum));
    }
}

// Print the result formatted to three decimal places
System.out.printf("%.3f", res);

