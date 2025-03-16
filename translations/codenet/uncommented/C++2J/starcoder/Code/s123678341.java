import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int X = in.nextInt();
        int Y = in.nextInt();
        int Z = in.nextInt();
        int K = in.nextInt();
        int[] A = new int[X];
        int[] B = new int[Y];
        int[] C = new int[Z];
        for(int i=0; i<X; i++)
            A[i] = in.nextInt();
        for(int i=0; i<Y; i++)
            B[i] = in.nextInt();
        for(int i=0; i<Z; i++)
            C[i] = in.nextInt();
        
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        
        List<Integer> AB = new ArrayList<Integer>();
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){
                AB.add(A[i]+B[j]);
            }
        }
        
        Collections.sort(AB);
        List<Integer> ABC = new ArrayList<Integer>();
        for(int i=0; i<Math.min(K, AB.size()); i++){
            for(int j=0; j<Z; j++){
                ABC.add(AB.get(i) + C[j]);
            }
        }
        
        Collections.sort(ABC);
        for(int i=0; i<K; i++){
            System.out.println(ABC.get(i));
        }
    }
}

