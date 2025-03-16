import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int b = sc.nextInt();
            int e = sc.nextInt();
            reverse(a, b, e);
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(a[i]);
        }
        System.out.println();
        
        sc.close();
    }
    
    private static void reverse(int[] arr, int start, int end) {
        // Adjusting end to be inclusive
        end--; 
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}

// <END-OF-CODE>
