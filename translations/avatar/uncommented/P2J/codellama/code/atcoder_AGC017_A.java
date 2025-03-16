
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int P = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] % 2 == P) {
                count++;
            }
        }
        int[] arr1 = new int[count];
        int[] arr2 = new int[N - count];
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] % 2 == P) {
                arr1[j] = arr[i];
                j++;
            } else {
                arr2[j] = arr[i];
                j++;
            }
        }
        int[] arr3 = new int[count];
        int[] arr4 = new int[N - count];
        for (int i = 0; i < count; i++) {
            arr3[i] = arr1[i] % 2;
        }
        for (int i = 0; i < N - count; i++) {
            arr4[i] = arr2[i] % 2;
        }
        int count1 = 0;
        for (int i = 0; i < count; i++) {
            if (arr3[i] == 1) {
                count1++;
            }
        }
        int count2 = 0;
        for (int i = 0; i < N - count; i++) {
            if (arr4[i] == 1) {
                count2++;
            }
        }
        int[] arr5 = new int[count1];
        int[] arr6 = new int[count2];
        int k = 0;
        for (int i = 0; i < count; i++) {
            if (arr3[i] == 1) {
                arr5[k] = arr1[i];
                k++;
            }
        }
        int l = 0;
        for (int i = 0; i < N - count; i++) {
            if (arr4[i] == 1) {
                arr6[l] = arr2[i];
                l++;
            }
        }
        int count3 = 0;
        for (int i = 0; i < count1; i++) {
            for (int j = 0; j < count2; j++) {
                if (arr5[i] + arr6[j] == P) {
                    count3++;
                }
            }
        }
        System.out.println(count3);
    }
}



