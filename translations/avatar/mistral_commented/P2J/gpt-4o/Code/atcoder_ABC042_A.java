import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read user input and split it by space
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        
        // Convert the input strings to integers and store them in an array
        int[] ABC = new int[inputArray.length];
        for (int i = 0; i < inputArray.length; i++) {
            ABC[i] = Integer.parseInt(inputArray[i]);
        }
        
        // Count occurrences of the integer '5'
        int countOfFive = 0;
        for (int num : ABC) {
            if (num == 5) {
                countOfFive++;
            }
        }
        
        // Check the conditions and print the result
        if (countOfFive == 2) {
            int sum = 0;
            for (int num : ABC) {
                sum += num;
            }
            System.out.println(sum == 17 ? "YES" : "NO");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
