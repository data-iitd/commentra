
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // BufferedReader to read input from standard input
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    
    // Read the number of test cases
    int t = Integer.parseInt(br.readLine()); 
    
    // Arrays and priority queues for processing input
    String[] s; 
    PriorityQueue<Integer> pqmax = new PriorityQueue<Integer>(); // Min-heap for maximum values
    PriorityQueue<Integer> pqmin = new PriorityQueue<Integer>(new Comparator<Integer>() { 
        // Max-heap for minimum values
        public int compare(Integer x, Integer y) { 
            return y - x; 
        } 
    }); 
    
    // Variables to store sums and minimum value
    long sumMin = 0, sumMax = 0, sumb = 0; 
    int min = 0; 
    
    // Process each test case
    while (t-- > 0) { 
        // Read the input line and split it into parts
        s = br.readLine().split(" "); 
        
        // If the first character is '2', calculate and print the result
        if (s[0].charAt(0) == '2') { 
            long ans = min; 
            ans *= pqmin.size(); 
            ans -= sumMin; 
            long ans1 = min; 
            ans1 *= pqmax.size(); 
            ans1 = sumMax - ans1; 
            
            // Print the minimum value and the calculated result
            cout << min << " " << (ans + ans1 + sumb) << endl; 
        } else { 
            // Parse the input values
            int in = Integer.parseInt(s[1]); 
            sumb += Long.parseLong(s[2]); // Update the sum of additional values
            
            // Add the input value to the appropriate priority queue
            if (in > min) { 
                pqmax.add(in); 
                sumMax += in; 
            } else { 
                pqmin.add(in); 
                sumMin += in; 
            } 
            
            // Balance the two heaps if necessary
            if (pqmin.size() > pqmax.size()) { 
                sumMax += pqmin.peek(); 
                sumMin -= pqmin.peek(); 
                pqmax.add(pqmin.poll()); 
            } 
            if (pqmin.size() < pqmax.size()) { 
                sumMax -= pqmax.peek(); 
                sumMin += pqmax.peek(); 
                pqmin.add(pqmax.poll()); 
            } 
            
            // Update the minimum value based on the current state of the heaps
            min = pqmin.peek(); 
        } 
    } 
}

