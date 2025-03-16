
import java.util.*;

public class s107204188{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int minA = (int)Math.pow(10,9) + 1;
        int num = 0;
        
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] A = new int[n];
        
        for(int i = 0; i < n; i++){
            A[i] = sc.nextInt();
        }
        
        for(int i = 0; i < n; i++){
            if(minA > A[i]){
                minA = A[i];
            }else{
                
                if(f == A[i] - minA)num++;
                else if(f < A[i] - minA){
                    num = 1;
                    f = A[i] - minA;
                }
                
            }
        }
        
        System.out.println(num);
    }
}
