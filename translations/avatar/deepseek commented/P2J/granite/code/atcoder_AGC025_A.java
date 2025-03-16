

Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input from the user.
String n = scanner.nextLine();  // Reading a line of input from the user and storing it in the variable `n`.
List<String> a = Arrays.asList("10", "100", "1000", "10000", "100000");  // Creating a list `a` containing string representations of numbers.
int new = 0;  // Initializing a variable `new` to store the sum of the digits of `n`.
for (char c : n.toCharArray()) {  // Iterating over each character in the string `n`.
    new += Character.getNumericValue(c);  // Adding the numeric value of the current character to `new`.
}
if (a.contains(n)) {  // Checking if the string `n` is in the list `a`.
    System.out.println(10);  // If `n` is in `a`, print the number 10.
} else {  // Otherwise...
    System.out.println(new);  // Print the value of `new`.
}
// END-OF-CODE