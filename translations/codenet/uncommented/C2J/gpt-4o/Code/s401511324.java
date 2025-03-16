import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[2001];
        
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sorting the array
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (l[j] < l[i]) {
                    int tmp = l[i];
                    l[i] = l[j];
                    l[j] = tmp;
                }
            }
        }
        
        int cnt = 0;
        
        // Counting valid triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (l[i] + l[j] > l[k]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
        
        System.out.println(cnt);
        scanner.close();
    }
}

// <END-OF-CODE>
