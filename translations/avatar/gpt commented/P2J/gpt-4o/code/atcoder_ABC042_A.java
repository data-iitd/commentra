import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of input, split it into components, and convert each component to an integer, storing them in an array
        String[] input = scanner.nextLine().split(" ");
        int[] ABC = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            ABC[i] = Integer.parseInt(input[i]);
        }
        
        // Check if the number 5 appears exactly twice in the array
        int count5 = 0;
        int sum = 0;
        for (int num : ABC) {
            if (num == 5) {
                count5++;
            }
            sum += num;
        }
        
        // If 5 appears twice, check if the sum of the numbers in the array equals 17
        if (count5 == 2) {
            System.out.println(sum == 17 ? "YES" : "NO");
        } else {
            // If 5 does not appear exactly twice, print 'NO'
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
