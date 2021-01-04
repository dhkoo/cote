#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> g[], bool check[], int start) {
  queue<int> q;
  q.push(start);
  check[start] = true;

  while (!q.empty()) {
    int target = q.front();
    q.pop();
    cout << target << endl;
    for (int i = 0; i < g[target].size(); ++i) {
      if (!check[g[target][i]]) {
        q.push(g[target][i]);
        check[g[target][i]] = true;
      }
    }
  }
}

void dfs(vector<int> g[], bool check[], int start) {
  check[start] = true;
  cout << start << endl;

  for (int i = 0; i < g[start].size(); ++i) {
    int target = g[start][i];
    if (!check[target]) {
      dfs(g, check, target);
    }
  }
}

int main() {
  vector<int> g[5];
  bool check[5] = {false,};
  g[0].push_back(1);
  g[0].push_back(2);
  g[0].push_back(3);
  g[1].push_back(4);

  //bfs(g, check, 0);
  dfs(g, check, 0);
  return 0;
}
