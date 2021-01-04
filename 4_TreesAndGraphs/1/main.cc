/* 노드 사이의 경로:
 * 방향 그래프가 주어졌을 때 두 노드 사이에 경로가 존재하는지 확인하는 
 * 알고리즘을 작성하라.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasPath(vector<int> g[], bool check[], int start, int dest) {
  queue<int> q;
  q.push(start);
  check[start] = true;

  while (!q.empty()) {
    int target = q.front();
    q.pop();

    for (int i = 0; i < g[target].size(); ++i) {
      if (!check[g[target][i]]) {
        q.push(g[target][i]);
        check[g[target][i]] = true;
        if (g[target][i] == dest) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  vector<int> g[5];
  bool check[5] = {false,};
  g[0].push_back(1);
  g[0].push_back(2);
  g[0].push_back(3);
  g[1].push_back(4);

  if (hasPath(g,check,0,4)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
