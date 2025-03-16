import java.util.*;
public class LinearSearch{
  public static void main(String args[]){
    int i,n,s[],q,t,count=0;

    // Read the number of elements
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();

    // Read the elements into the array s
    s=new int[n];
    for(i=0;i<n;i++){
      s[i]=sc.nextInt();
    }

    // Read the number of queries
    q=sc.nextInt();

    // Perform a linear search for each query
    for(i=0;i<q;i++){
      t=sc.nextInt();
      if( linersearch(s,n,t) ) count++;
    }

    // Print the total count of successful searches
    System.out.println(count);
  }

  public static boolean linersearch(int a[],int n,int key){
    int i=0;

    // Modify the array to facilitate the search
    a[n]=key;
    
    // Perform the linear search
    while(a[i]!=key){
      i++;
    }

    // Return true if the key is found, false otherwise
    return i!=n;
  }
}
