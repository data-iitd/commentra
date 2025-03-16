
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X,A,B,C;
        int i=0;
        int j=0;
        int k=0;
        int kosu=0;
  
 // 整数の入力
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        X = sc.nextInt();
  
  X=X/50;
  
   for(i=0;i<=A;i++){
     for(j=0;j<=B;j++){
       for(k=0;k<=C;k++){
         if(X==(10*i)+(2*j)+k) kosu++;
       }
     }
   }
  
     

  System.out.println(kosu);

}
