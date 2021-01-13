/* Route Between Nodes
 * Given direted graph, check whelther it has route.
 */

#include "../graph.h"
#include <queue>
#include <set>
using namespace std;

bool search(Graph &graph, int start, int end) {
  if (start == end)
    return true;

  queue<int> q;
  set<int> visited;

  for (auto node : graph.getNodes()[start]) {
    q.push(node);
    visited.insert(node);
  }

  int c = 0;
  while (!q.empty()) {
    c = q.front();
    q.pop();
    if (c == end) {
      return true;
    }
    for (auto node : graph.getNodes()[c]) {
      if (visited.find(node) == visited.end())
        q.push(node);
    }
  }

  return false;
};

int main() {
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(0, 2);
  graph.addEdge(2, 3);
  graph.addEdge(4, 2);

  graph.printNode();
  auto res = search(graph, 0, 2);

  return 0;
}