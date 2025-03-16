// Prompt the user to input their age and convert it to an integer
int age = Integer.parseInt(input());

// Check if the age is equal to 1
if (age == 1) {
    // If age is 1, print 'Hello World'
    System.out.println("Hello World");
} else {
    // If age is not 1, prompt the user to input two integers
    int a = Integer.parseInt(input());
    int b = Integer.parseInt(input());
    // Calculate and print the sum of the two integers
    System.out.println(a + b);
}

