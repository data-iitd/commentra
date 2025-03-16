import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;
        
        while (counter < a.length) {
            counterTurns++;
            for (int i = 0; i < a.length; i++) {
                if (a[i] != -1 && a[i] <= counter) {
                    counter++;
                    a[i] = -1;
                }
            }
            reverseArray(a);
        }
        
        System.out.println(counterTurns);
        scanner.close();
    }
    
    private static void reverseArray(int[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}

// <END-OF-CODE>
