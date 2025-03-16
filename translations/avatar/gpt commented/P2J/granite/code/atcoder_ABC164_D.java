
// Read input string and set the length variable
String s = scanner.nextLine();
int l = 2019;

// Initialize a list to count occurrences of remainders, and variables for accumulated value and result
List<Integer> m = new ArrayList<>(Collections.nCopies(l, 1));
int a = 0, r = 0;

// Iterate over the input string in reverse order
for (int i = s.length() - 1; i >= 0; i--) {
    // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
    a = (a + (s.charAt(i) - '0') * (int) Math.pow(10, s.length() - 1 - i, l)) % l;
    
    // Update the result 'r' by adding the count of occurrences of the current remainder
    r += m.get(a);
    
    // Increment the count of the current remainder in the list'm'
    m.set(a, m.get(a) + 1);
}

// Print the final result
System.out.println(r);
