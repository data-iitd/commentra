
#define MIN(a, b) ((a < b)? a : b)
#define INF 1000000001
#define N 100000

class edge:
  def __init__(self, source, target, weight):
    self.source = source
    self.target = target
    self.weight = weight

edges = []

distances = [INF] * N
prev_distances = [0] * N

def main():
  V, E, r = map(int, raw_input().split())

  for i in range(E):
    source, target, distance = map(int, raw_input().split())
    new_edge = edge(source, target, distance)
    edges.append(new_edge)

  #initialize distances array
 
  for i in range(N):
    distances[i] = INF #max value
  distances[r] = 0

 
  for i in range(1, V):
    for j in range(V):
      prev_distances[j] = distances[j]  
    for edgeptr in edges:
      distances[edgeptr.target] = MIN(distances[edgeptr.source] + edgeptr.weight, distances[edgeptr.target])
    
    same = True
    for j in range(V):
      if (distances[j]!= prev_distances[j]):
	same = False
	break

    if (same): break;
  for i in range(V):
    if (distances[i] == INF):
      print "INF"
    else:
      print distances[i]

if __name__ == "__main__":
  main()

