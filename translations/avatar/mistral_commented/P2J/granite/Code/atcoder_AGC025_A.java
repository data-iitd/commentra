
// Take an input from the user and assign it to the variable 'n'
Scanner sc = new Scanner(System.in);
String n = sc.nextLine();

// Initialize a list 'a' with some strings representing numbers
List<String> a = Arrays.asList("10", "100", "1000", "10000", "100000");

// Convert each element of the input 'n' to an integer using the'stream' method
// and then sum up all the integers using the'reduce' method and assign the result to the variable 'new'
int new = Arrays.stream(n.split(""))
                   .mapToInt(Integer::parseInt)
                   .sum();

// Check if the input 'n' is present in the list 'a'
if (a.contains(n)) {
    // If the input 'n' is present in the list 'a', then print the number 10
    System.out.println(10);
} else {
    // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
    System.out.println(new);
}

// End of code
