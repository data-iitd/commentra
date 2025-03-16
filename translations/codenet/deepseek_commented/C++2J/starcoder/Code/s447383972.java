import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws Exception{
        // Step 1: Read the size of the array.
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        // Step 2: Read the elements of the array.
        int[] a=new int[n+1];
        for(int i=1;i<=n;i++)    a[i]=Integer.parseInt(br.readLine());
        // Step 3: Sort the array.
        Arrays.sort(a);
        // Step 4: Remove duplicates from the array.
        int tot=0;
        for(int i=1;i<=n;i++)    if (a[i]==a[i+1])    q[++tot]=a[i],i++;
        // Step 5: Print the product of the two largest distinct elements.
        System.out.println(q[tot]*q[tot-1]);
    }
}
