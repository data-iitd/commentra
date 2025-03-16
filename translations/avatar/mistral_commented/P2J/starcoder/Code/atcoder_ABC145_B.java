// Read an integer value from the user
int n = Integer.parseInt(input());

// Read a string value from the user
String s = input();

// Check if n is odd
if (n % 2!= 0) {
    System.out.println("No");
}

// Check if the first half of the string is equal to the second half
else if (s.substring(0, n/2).equals(s.substring(n/2, n))) {
    System.out.println("Yes");
}

// If the first half is not equal to the second half, print 'No'
else {
    System.out.println("No");
}

