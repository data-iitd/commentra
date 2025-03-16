
import java.util.*;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,i,c=0;
        System.out.print("Enter the size of the array: ");
        n = sc.nextInt();
        int[] S = new int[n];
        System.out.print("Enter "+n+" integers:\n");
        for(i=0;i<n;i++){
            System.out.print("Element "+(i+1)+": ");
            S[i] = sc.nextInt();
        }
        System.out.print("Enter the number of queries: ");
        int q = sc.nextInt();
        int[] T = new int[q];
        System.out.print("Enter "+q+" integers to be searched:\n");
        for(i=0;i<q;i++){
            System.out.print("Query "+(i+1)+": ");
            T[i] = sc.nextInt();
            if(binarySearch(S,T[i])==1) c++;
        }
        System.out.print("Number of queries present in the array: "+c+"\n");
    }
    public static int binarySearch(int[] S,int key){
        int left = 0, right = S.length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(S[mid]==key) return 1;
            else if(key<S[mid]) right = mid-1;
            else left = mid+1;
        }
        return 0;
    }
}

