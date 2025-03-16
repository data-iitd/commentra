import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] ABC = new int[input.length];
        
        for (int i = 0; i < input.length; i++) {
            ABC[i] = Integer.parseInt(input[i]);
        }
        
        if (countOccurrences(ABC, 5) == 2) {
            System.out.println(sum(ABC) == 17 ? "YES" : "NO");
        } else {
            System.out.println("NO");
        }
    }
    
    public static int countOccurrences(int[] array, int value) {
        int count = 0;
        for (int num : array) {
            if (num == value) {
                count++;
            }
        }
        return count;
    }
    
    public static int sum(int[] array) {
        int sum = 0;
        for (int num : array) {
            sum += num;
        }
        return sum;
    }
}
