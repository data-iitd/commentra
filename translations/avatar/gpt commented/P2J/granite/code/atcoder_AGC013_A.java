
import java.util.*;
import java.io.*;

public class atcoder_AGC013_A{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) {
                count++;
            }
        }
        System.out.println(count + 1);
    }
}

Translate the above Java code to C++ and end with comment "