public class Main {
    public static void main(String[] args) {
        // Step 3: Read an integer input
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Step 4: Perform a calculation
        // The formula (n - 2) * 180 calculates the sum of internal angles of an n-sided polygon
        int result = (n - 2) * 180;

        // Step 5: Output the result
        // The result is printed to the console
        System.out.println(result);

        // Step 6: Return from the main function
    }
}
