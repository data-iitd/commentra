import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take input from user and split it into integers
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        int[] ABC = new int[inputArray.length];
        
        for (int i = 0; i < inputArray.length; i++) {
            ABC[i] = Integer.parseInt(inputArray[i]);
        }
        
        // Check if the array contains exactly two 5s
        int countOfFives = 0;
        for (int num : ABC) {
            if (num == 5) {
                countOfFives++;
            }
        }
        
        // Check if the sum of the elements in ABC is 17
        int sum = 0;
        for (int num : ABC) {
            sum += num;
        }
        
        if (countOfFives == 2) {
            System.out.println(sum == 17 ? "YES" : "NO");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
