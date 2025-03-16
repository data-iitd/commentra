import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] tomatu = new int[N];
        boolean[] mikakosi = new boolean[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            tomatu[i] = A[i];
        }
        
        Arrays.sort(tomatu);
        int yukinnko = 1;
        for (int i = 1; i < N; i++) {
            if (tomatu[i] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[i];
            }
        }
        
        for (int i = 0; i < N; i++) {
            int kugyu = binarySearch(tomatu, A[i]);
            mikakosi[kugyu] = !mikakosi[kugyu];
        }
        
        int emirinn = 0;
        for (int i = 0; i < yukinnko; i++) {
            if (mikakosi[i]) emirinn++;
        }
        
        System.out.println(emirinn);
    }
    
    public static int binarySearch(int[] array, int target) {
        int left = 0, right = array.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == target) return mid;
            else if (array[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1; // This should not happen in this context
    }
}
