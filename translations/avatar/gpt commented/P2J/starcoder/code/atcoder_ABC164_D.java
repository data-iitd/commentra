// Read input string and set the length variable
String s = input();
int l = 2019;

// Initialize a list to count occurrences of remainders, and variables for accumulated value and result
int[] m = new int[l + 1];
int a = 0, r = 0;

// Iterate over the input string in reverse order
for (int i = s.length() - 1; i >= 0; i--) {
    // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
    a += (int) s.charAt(i) * Math.pow(10, i, l);
    
    // Update the result 'r' by adding the count of occurrences of the current remainder
    r += m[a % l];
    
    // Increment the count of the current remainder in the list'm'
    m[a % l] += 1;
}

// Print the final result
System.out.println(r);

