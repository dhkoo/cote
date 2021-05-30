/*
 * projects 리스트와 dependencies 리스트가 있을때 빌드 순서를 정해라
 * 디펜던시가 사이클링이 생기면 error 리턴
 */

#include "../graph.h"
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

enum PROJECT { a, b, c, d, e, f };

Graph buildGraph(vector<PROJECT> projects,
                 vector<pair<PROJECT, PROJECT>> dependencies);

vector<PROJECT> topologySort(vector<PROJECT> projects,
                           vector<pair<PROJECT, PROJECT>> dependencies) {

  vector<PROJECT> order;
  Graph graph = buildGraph(projects, dependencies);
  auto inDegree = graph.getInDegree();
  // 초기 
  queue<int> searching;
  for(int inOrder: inDegree){
    if(inOrder==0)
      searching.emplace(inOrder);
  }

  for(int i=0; i<graph.getNumNode();++i){
    int v = searching.front();
    searching.pop();

    order.push_back(static_cast<PROJECT>(v));

    for(int conectedVertex: graph.getNodes()[v]){
      --inDegree[conectedVertex];

      if(inDegree[conectedVertex]==0)
        searching.push(conectedVertex);    
    }
  }
  return order;
}


Graph buildGraph(vector<PROJECT> projects,
                 vector<pair<PROJECT, PROJECT>> dependencies) {
  Graph dependencyGraph(projects.size());

  for (auto dependency : dependencies) {

    dependencyGraph.addEdge(dependency.first, dependency.second);
  }

  return dependencyGraph;
}

int main() {
  vector<PROJECT> projects = {a, b, c, d, e, f};
  vector<pair<PROJECT, PROJECT>> dependencies;
  dependencies.push_back(make_pair(a, b));
  dependencies.push_back(make_pair(f, b));
  dependencies.push_back(make_pair(b, d));
  dependencies.push_back(make_pair(f, a));
  dependencies.push_back(make_pair(d, c));

  auto res = topologySort(projects, dependencies);
  return 0;
}