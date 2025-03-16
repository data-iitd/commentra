import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define variables x and y by unpacking the array returned by the split method
        String[] input = scanner.nextLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        
        // Helper functions for simplifying input process
        int num_inp() {
            return Integer.parseInt(scanner.nextLine());
        }

        int[] arr_inp() {
            String[] inputArray = scanner.nextLine().split(" ");
            int[] result = new int[inputArray.length];
            for (int i = 0; i < inputArray.length; i++) {
                result[i] = Integer.parseInt(inputArray[i]);
            }
            return result;
        }

        int[] sp_inp() {
            String[] inputArray = scanner.nextLine().split(" ");
            int[] result = new int[inputArray.length];
            for (int i = 0; i < inputArray.length; i++) {
                result[i] = Integer.parseInt(inputArray[i]);
            }
            return result;
        }

        String str_inp() {
            return scanner.nextLine();
        }

        // Calculate and print the maximum value between x + y - 3 + ((y - x) % 3 > 0) and 0
        System.out.println(Math.max(x + y - 3 + ((y - x) % 3 > 0), 0));
    }
}
