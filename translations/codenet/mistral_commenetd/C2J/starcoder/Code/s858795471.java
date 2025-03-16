
import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n,A[]=new int[10000+1],q,key,sum=0,i;
        n=sc.nextInt();
        for(i=0;i<n;i++) A[i]=sc.nextInt();
        q=sc.nextInt();
        for(i=0;i<q;i++){
            key=sc.nextInt();
            if(search(A,n,key)) sum++;
        }
        System.out.println(sum);
    }
    public static boolean search(int A[],int n,int key){
        int i=0;
        A[n]=key;
        while(A[i]!=key) i++;
        return i!=n;
    }
}
