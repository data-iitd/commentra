
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int min_element = A[0];
        int max_element = A[0];
        for (int i = 0; i < N; i++) {
            if (A[i] < min_element) {
                min_element = A[i];
            }
            if (A[i] > max_element) {
                max_element = A[i];
            }
        }
        System.out.println("Difference between maximum and minimum elements: " + (max_element - min_element));
    }
}

