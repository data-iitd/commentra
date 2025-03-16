#include <bits/stdc++.h>
using namespace std;

// Declare static members for output stream and print writer
static ostream outputStream = cout;
static ofstream out = ofstream(stdout);

int main() {
    // Initialize variables to keep track of sums and the minimum value
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    
    // Initialize priority queues for max and min values
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    
    // Initialize BufferedReader to read input from System.in
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    // Read the number of test cases
    int t = Integer.parseInt(br.readLine());
    
    // Process each test case
    while (t-- > 0) {
        // Read the input for the current test case
        String[] s = br.readLine().split(" ");
        
        // If the command is '2', calculate and print the result
        if (s[0].charAt(0) == '2') {
            long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            out.println(min + " " + (ans + ans1 + sumb));
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in = Integer.parseInt(s[1]);
            sumb += Long.parseLong(s[2]);
            
            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }
            
            // Balance the priority queues
            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
            
            if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }
            
            // Update the minimum value
            min = pqmin.top();
        }
    }
    
    // Close the print writer to flush the output
    out.close();
}

