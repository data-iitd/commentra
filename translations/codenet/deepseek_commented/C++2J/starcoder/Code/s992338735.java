import java.util.*;

public class Average{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      while ( sc.hasNextInt()){
         int N = sc.nextInt();
         if ( N == 0) break;
         int M = -1, m = 1001, addup = 0, i;
         for ( i = 0; i<N; i++){
            int S = sc.nextInt();
            addup += S;
            if ( S > M) M = S;
            if ( S < m) m = S;
         }
         System.out.println((addup - M - m)/(N-2));
      }
   }
}
