// Read input from the user
Scanner sc = new Scanner(System.in);
String n = sc.nextLine();

// Define a list of string representations of powers of ten
String[] a = {"10", "100", "1000", "10000", "100000"};

// Convert the input string into a list of integers and calculate the sum
int new = 0;
for (int i = 0; i < n.length(); i++) {
    new += Integer.parseInt(n.substring(i, i + 1));
}

// Check if the input is one of the predefined values in the list 'a'
if (Arrays.asList(a).contains(n)) {
    // If the input matches one of the predefined values, print 10
    System.out.println(10);
} else {
    // If the input does not match, print the calculated sum
    System.out.println(new);
}

