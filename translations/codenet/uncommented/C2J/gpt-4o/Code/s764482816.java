import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] io = new int[5];
        
        for (int i = 0; i < 5; i++) {
            io[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < 5; i++) {
            int max = io[i];
            int max_j = i;
            for (int j = i + 1; j < 5; j++) {
                if (max < io[j]) {
                    max = io[j];
                    max_j = j;
                }
            }
            // Swap
            int buf = io[i];
            io[i] = io[max_j];
            io[max_j] = buf;
            
            if (i < 4) {
                System.out.print(io[i] + " ");
            } else {
                System.out.println(io[i]);
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
