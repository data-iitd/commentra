
#include <bits/stdc++.h>

using namespace std;

// Initialize reader and writer
std::istream reader;
std::ostream writer;

// Function to read a single line from standard input
std::string NextLine() {
  std::string line;
  std::getline(reader, line);
  return line;
}

// Function to read an integer from standard input
int NextInt() {
  return std::stoi(NextLine());
}

// Function to write a value to standard output
void Write(const std::string& s) {
  writer << s << "\n";
}

// Function to flush the writer buffer
void Output() {
  writer.flush();
}

// Function to check if a given graph is bipartite
bool Bipartite(const std::vector<std::string>& S) {
  // Initialize number of vertices
  int N = S.size();

  // Initialize degree array
  std::vector<int> D(N);
  D[0] = 1;

  // Initialize queue
  std::vector<int> Q(N);

  // Initialize result
  bool ret = true;

  // Initialize position in queue
  int pos = 1;

  // Iterate over each vertex
  for (int i = 0; i < N; i++) {
    if (!ret) { break; }

    // Get current vertex
    int q = Q[i];

    // Iterate over each neighbor of the current vertex
    for (int j = 0; j < N; j++) {
      if (S[q][j] == '0') {
        continue;
      }

      // If neighbor is not visited yet
      if (D[j] == 0) {
        // Mark neighbor as visited
        D[j] = D[q] + 1;

        // Add neighbor to queue
        Q[pos] = j;
        pos++;

        // Continue to next neighbor
        continue;
      }

      // If degrees of current and neighbor are different
      if (D[j] % 2!= D[q] % 2) {
        // Graph is not bipartite
        ret = false;
        break;
      }
    }
  }

  // Return result
  return ret;
}

// Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
int WarshallFloyd(const std::vector<std::string>& S) {
  // Initialize number of vertices
  int N = S.size();

  // Initialize adjacency matrix
  std::vector<std::vector<int>> G(N, std::vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; }
      if (S[i][j] == '0') {
        G[i][j] = N;
      } else {
        G[i][j] = 1;
      }
    }
  }

  // Iterate over all vertices k
  for (int k = 0; k < N; k++) {
    // Iterate over all vertices i
    for (int i = 0; i < N; i++) {
      // Iterate over all vertices j
      for (int j = 0; j < N; j++) {
        // Update shortest distance if found
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j];
        }
      }
    }
  }

  // Initialize answer as maximum distance
  int ans = 0;

  // Iterate over all vertices i
  for (int i = 0; i < N; i++) {
    // Iterate over all vertices j
    for (int j = 0; j < N; j++) {
      // Update answer if found
      if (ans < G[i][j]) { ans = G[i][j]; }
    }
  }

  // Return answer plus one
  return ans + 1;
}

// Main function
int main() {
  // Read number of vertices
  int N = NextInt();

  // Initialize graph
  std::vector<std::string> S(N);
  for (int i = 0; i < N; i++) {
    S[i] = NextLine();
  }

  // Check if graph is bipartite
  if (!Bipartite(S)) {
    // Write -1 if graph is not bipartite
    Write("-1");
  } else {
    // Write shortest distance between all pairs of vertices
    Write(std::to_string(WarshallFloyd(S)));
  }

  // Flush writer buffer
  Output();
}

