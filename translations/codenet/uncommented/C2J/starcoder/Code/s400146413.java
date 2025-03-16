
import java.util.*;

public class LinearSearch {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] S = new int[n];
        for(int i = 0; i < n; i++){
            S[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        int[] T = new int[q];
        for(int j = 0; j < q; j++){
            T[j] = sc.nextInt();
        }
        int count = 0;
        for(int j = 0; j < q; j++){
            int key = T[j];
            for(int i = 0; i < n; i++){
                if(S[i] == key){
                    count++;
                    break;
                }
            }
        }
        System.out.println(count);
    }
}

