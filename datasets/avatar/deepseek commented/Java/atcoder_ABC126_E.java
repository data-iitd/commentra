
import java.util.* ; 

public class Main { 
    Scanner sc = new Scanner(System.in); 
    final int MOD = 1000000007; 
    
    void doIt() { 
        // Step 1: Read the input number of elements (n) and create a UnionFindTree instance.
        int n = sc.nextInt(); 
        UnionFindTree utf = new UnionFindTree(n); 
        
        // Step 2: Read the number of operations (m) and iterate through each operation.
        int m = sc.nextInt(); 
        for (int i = 0; i < m; i++) { 
            // Step 3: For each operation, read the two elements (x and y) and the operation type (z).
            int x = sc.nextInt() - 1; 
            int y = sc.nextInt() - 1; 
            int z = sc.nextInt(); 
            
            // Step 4: Perform the union operation on the elements x and y.
            utf.unite(x, y); 
        } 
        
        // Step 5: Count the number of connected components in the UnionFindTree and print the result.
        int cnt = 0; 
        for (int i = 0; i < n; i++) { 
            if (utf.par[i] == i) { 
                cnt++; 
            } 
        } 
        System.out.println(cnt); 
    } 
    
    class UnionFindTree { 
        int n; 
        int[] par; 
        int[] rank; 
        
        UnionFindTree(int n) { 
            this.n = n; 
            par = new int[n]; 
            rank = new int[n]; 
            for (int i = 0; i < n; i++) { 
                par[i] = i; 
                rank[i] = 0; 
            } 
        } 
        
        int find(int x) { 
            if (par[x] == x) { 
                return x; 
            } else { 
                return par[x] = find(par[x]); 
            } 
        } 
        
        void unite(int x, int y) { 
            x = find(x); 
            y = find(y); 
            if (x == y) return; 
            if (rank[x] < rank[y]) { 
                par[x] = y; 
            } else { 
                par[y] = x; 
                if (rank[x] == rank[y]) rank[x]++; 
            } 
        } 
        
        boolean same(int x, int y) { 
            return find(x) == find(y); 
        } 
    } 
    
    public static void main(String[] args) { 
        new Main().doIt(); 
    } 
}

