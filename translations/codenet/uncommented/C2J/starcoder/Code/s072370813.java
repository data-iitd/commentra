
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] A = new int[N];
        int sum = 0;
        int wa = 0;
        int[] sa = new int[N];
        int ans = 1;
        int shou = 0;
        int min = 1123456789;
        for(int i = 0; i < N; i++){
            A[i] = in.nextInt();
            sum += A[i];
            wa += i+1;
        }
        if(sum % wa!= 0) ans = 0;
        else{
            shou = sum/wa;
            for(int i = 0; i < N; i++){
                sa[i] = A[(i+1)%N] - A[i] - shou;
            }
            for(int i = 0; i < N-1; i++){
                if(sa[i] <= 0 &&!(sa[i] % N)) ans = 1;
                else{
                    ans = 0;
                    break;
                }
            }
        }
        if(ans) System.out.println("YES");
        else System.out.println("NO");
    }
}

