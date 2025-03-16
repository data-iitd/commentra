import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    int q = sc.nextInt();
    int[] a = new int[q];
    long[] point = new long[n];
    for(int i = 0; i < q; i++){
      a[i] = sc.nextInt();
      point[a[i] - 1]++;
    }
    for(int i = 0; i < n; i++){
      if(k - (q - point[i]) > 0){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
    }
  }
}
