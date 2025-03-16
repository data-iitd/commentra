// Read an integer input from the user
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Read a string input from the user
String s = sc.next();

// Check if the length of the string is odd
if (n % 2!= 0) {
    // If the length is odd, print 'No' since it cannot be split into two equal halves
    System.out.println("No");
} else {
    // Check if the first half of the string is equal to the second half
    if (s.substring(0, n / 2).equals(s.substring(n / 2, n))) {
        // If both halves are equal, print 'Yes'
        System.out.println("Yes");
    } else {
        // If the halves are not equal, print 'No'
        System.out.println("No");
    }
}

