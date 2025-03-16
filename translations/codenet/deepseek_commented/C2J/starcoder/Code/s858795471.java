import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n,A[],q,key,sum=0;
        int i;
        
        // Read the size of the array
        n=sc.nextInt();
        // Read the array elements
        A=new int[n];
        for(i=0;i<n;i++) A[i]=sc.nextInt();
        // Read the number of queries
        q=sc.nextInt();
        // Process each query
        for(i=0;i<q;i++){
            key=sc.nextInt();
            // Perform the search operation for the current query element
            if(search(A,n,key)) sum++;
        }
        // Print the count of successful searches
        System.out.println(sum);
    }
    public static boolean search(int A[],int n,int key){
        int i=0;
        // Add the key to the end of the array to handle the case where the key is not found
        A[n]=key;
        // Loop until the key is found in the array
        while(A[i]!=key) i++;
        // Return 1 if the key is found, otherwise return 0
        return i!=n;
    }
}
