
import java.util.*;
import java.io.*;

class s072370813{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] A = new int[N];
    int i;
    long sum = 0;
    long wa = 0;
    int ans = 0;
    int shou;
    long min = 1123456789;
    
    for( i = 0; i < N; i++ ){
      A[i] = sc.nextInt();
      sum += A[i];
      wa += i+1;
    }
    
    if( sum % wa ) ans = 0;
    else{
      shou = (int)(sum/wa);
      for( i = 0; i < N; i++ ){
        if( A[(i+1)%N] - A[i]-shou <= 0 && (A[(i+1)%N] - A[i]-shou) % N!= 0){
          ans = 1;
          break;
        }
      }
    }  
    if( ans ) System.out.println("YES");
    else System.out.println("NO");
  }
}
