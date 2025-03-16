import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input number N
        int N = scanner.nextInt();
        
        // Read the list A, which consists of five integers
        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Calculate the minimum value in the list A
        int minValue = Integer.MAX_VALUE;
        for (int value : A) {
            if (value < minValue) {
                minValue = value;
            }
        }
        
        // Calculate the ceiling value of N divided by the minimum value in the list A
        int ceilingValue = (int) Math.ceil((double) N / minValue);
        
        // Add 4 to the ceiling value to get the final answer
        int finalAnswer = ceilingValue + 4;
        
        // Print the final answer
        System.out.println(finalAnswer);
    }
}
