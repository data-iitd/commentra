
import java.util.Scanner;
 
public class InsertionSort {
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
 
        int num = sc.nextInt();
 
        int[] arr = new int[num];
 
        for (int i = 0; i < num; i++) {
            arr[i] = sc.nextInt();
        }
 
        sort(arr);
 
        for (int i = 0; i < num; i++) {
            System.out.print(arr[i] + " ");
        }
    }
 
    public static void sort(int[] arr) {
 
        for (int i = 0; i < arr.length; i++) {
            if (i!= 0) {
                int temp = arr[i];
                int j = i - 1;
                while ((j >= 0) && (arr[j] > temp)) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = temp;
            }
 
            for (int k = 0; k < arr.length; k++) {
                System.out.print(arr[k] + " ");
            }
            System.out.println();
        }
    }
}
