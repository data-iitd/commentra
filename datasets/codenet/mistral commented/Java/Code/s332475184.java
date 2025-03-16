import java.util.*;
import java.io.*;

class Main{
    // Declare static integer array 'counter' and static List 'graph'
    static int[] counter ;
    static List<List<Integer>> graph;

    public static void main(String[] args){
        // Initialize FastScanner object 'fs'
        FastScanner fs = new FastScanner();

        // Read number of vertices 'n' and number of queries 'q'
        int n = fs.nextInt();
        int q = fs.nextInt();

        // Initialize 'graph' with size 'n' and add empty LinkedList for each vertex
        graph = new ArrayList<>();
        for(int i=0;i<n;i++)graph.add(new LinkedList<>());

        // Declare and initialize 'counter' array with size 'n'
        counter = new int[n];

        // Read edges and add them to the graph
        for(int i=0;i<n-1;i++){
            // Read two vertices 'a' and 'b'
            Integer a = fs.nextInt()-1;
            Integer b = fs.nextInt()-1;

            // Add edge between 'a' and 'b' to the graph
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Read queries and update 'counter' array accordingly
        for(int i=0;i<q;i++){
            int index = fs.nextInt()-1; // Read index of vertex
            int value = fs.nextInt();   // Read value to add to the counter of the vertex
            counter[index] += value;
        }

        // Call 'dfs' function starting from vertex 0 with parent as -1 and value as 0
        dfs(0,-1,0);

        // Print the updated 'counter' array
        StringJoiner sj = new StringJoiner(" ");
        for(int i=0;i<n;i++){
            sj.add(String.valueOf(counter[i]));
        }
        System.out.println(sj.toString());
    }

    // Recursive depth first search function to update 'counter' array
    static void dfs(int v,int par,long val){
        for(Integer i: graph.get(v)){
            if(i!=par){ // Check if current vertex 'i' is not the parent of 'v'
                dfs(i,v,val+counter[v]); // Recursively call 'dfs' function for vertex 'i' with parent as 'v' and value as sum of 'counter[v]' and 'val'
            }
        }
        // Update 'counter' array for the current vertex 'v'
        counter[v] += val;
    }

    // FastScanner class to read input efficiently
    static class FastScanner{
        // Initialize input stream 'in' and byte array 'buffer'
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];

        // Initialize pointers 'ptr' and 'buflen'
        private int ptr = 0;
        private int buflen = 0;

        // Function to check if there is next byte available in the buffer
        private boolean hasNextByte(){
            if(ptr < buflen){
                return true;
            }else{
                ptr = 0;
                try{
                    buflen = in.read(buffer);
                }catch(IOException e){
                    e.printStackTrace();
                }
                if(buflen <= 0){
                    return false;
                }
            }
            return true;
        }

        // Function to read a single byte
        private int readByte(){
            if(hasNextByte())return buffer[ptr++];
            else return -1;
        }

        // Function to check if the current byte is printable character
        private boolean isPrintableChar(int c){
            return 33<=c && c<=126;
        }

        // Function to check if there is next token available
        public boolean hasNext(){
            while(hasNextByte() && !isPrintableChar(buffer[ptr]))ptr++;
            return hasNextByte();
        }

        // Function to read next token as String
        public String next(){
            if(!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)){
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        // Function to read next long integer
        public long nextLong(){
            if(!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if(b == '-'){
                minus = true;
                b = readByte();
            }
            if(b < '0' || '9' < b){
                throw new NumberFormatException();
            }
            while(true){
                if('0' <= b && b<='9'){
                    n*=10;
                    n+=b-'0';
                }else if(b==-1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
        // Function to read next integer
        public int nextInt(){
            long nl = nextLong();
            if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)throw new NumberFormatException();
            return (int)nl;
        }
        // Function to read next double
        public double nextDouble(){return Double.parseDouble(next());}
    }
}
