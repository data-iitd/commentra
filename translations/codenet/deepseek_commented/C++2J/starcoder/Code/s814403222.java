import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(true){
      int n = sc.nextInt();
      if(n == 0) break;
      int m;
      for(int i = 0; i < 33; i++) d[i].clear(); // Clear all vectors in d
      for(int i = 0; i < n; i++){ // Read m for each element
	v[i].first = 0; // Initialize the first element of v to 0
	v[i].second = sc.next(); // Read the string and m
	m = sc.nextInt();
	for(int j = 0; j < m; j++){ // For each m, read an integer and update v and d
	  int a = sc.nextInt();
	  v[i].first += n - d[a].size(); // Update the first element of v
	  for(int k = 0; k < d[a].size(); k++){ // Update the first elements of other v elements
	    v[d[a][k]].first--;
	  }
	  d[a].add(i); // Store the index of the current element in d
	}
      }
      Arrays.sort(v, new Comparator<P>(){ // Sort the array v based on the first element of P
	public int compare(P a, P b){
	  return a.first - b.first;
	}
      });
      System.out.println(v[0].first + " " + v[0].second); // Output the first element of v
    }
  }
}
