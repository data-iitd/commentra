import java.util.Scanner;

public class TriangleCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[2001];
        
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the array in ascending order using bubble sort
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (l[j] < l[i]) {
                    int tmp = l[i];
                    l[i] = l[j];
                    l[j] = tmp;
                }
            }
        }
        
        // Count the number of valid triangles that can be formed
        int cnt = 0;
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
        
        // Print the count of valid triangles
        System.out.println(cnt);
        scanner.close();
    }
}

// <END-OF-CODE>
