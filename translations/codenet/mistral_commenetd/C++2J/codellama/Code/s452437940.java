// Main function begins here
public static void main(String[] args)
{
    // Declare variables
    long a, b, x;

    // Read input values from standard input
    Scanner sc = new Scanner(System.in);
    a = sc.nextLong();
    b = sc.nextLong();
    x = sc.nextLong();

    // Calculate the difference between the number of complete x-blocks in b and a
    long s = (b/x - a/x);

    // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
    if(a%x == 0) s++;

    // Print the result to standard output
    System.out.println(s);

    // End of main function
}
