
import java.util.Scanner;
 
public class InsertionSort {
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
 
        int num = sc.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < num; i++) {
            array[i] = sc.nextInt();
        }
 
        sort(array);
 
        for (int i = 0; i < num; i++) {
            System.out.print(array[i]);
            if (i!= num - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
 
    public static void sort(int[] array) {
 
        for (int i = 0; i < array.length; i++) {
 
            if (i!= 0) {
 
                int intValue = array[i];
                int j = i - 1;
                while ((j >= 0) && (array[j] > intValue)) {
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = intValue;
            }
 
            for (int k = 0; k < array.length; k++) {
                System.out.print(array[k]);
                if (k!= array.length - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
