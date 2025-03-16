public class PossibleSums {
    static final int N = 2000;
    static int[] math = new int[N + 1];

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int num1, num2, a, ans, sum = 0;
        int i, j;

        // Initialize the first element of the math array to 1
        math[0] = 1;

        // Read the number of elements for the first set
        num1 = scanner.nextInt();
        
        // Loop to read each element and update the possible sums
        for(i = 0; i < num1; i++) {
            a = scanner.nextInt(); // Read the current element
            sum += a; // Update the total sum
            
            // Update the math array to reflect the new possible sums
            for(j = sum - a; j >= 0; j--) {
                if(math[j] == 1) {
                    math[j + a] = 1; // Mark the new sum as possible
                }
            }
        }

        // Read the number of queries for possible sums
        num2 = scanner.nextInt();
        
        // Loop to check if each queried sum is possible
        for(i = 0; i < num2; i++) {
            ans = scanner.nextInt(); // Read the queried sum
            // Check if the queried sum is possible and print the result
            System.out.println(math[ans] == 1 ? "yes" : "no");
        }

        scanner.close(); // Close the scanner
    }
}
