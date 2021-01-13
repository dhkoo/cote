#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>
#include <vector>
using namespace std;
enum nodeName { A, B, C, D, E, F, G, H }; // name of

class Graph {

public:
  Graph(int numNode) : _numEdge(0), _numNode(numNode) {
    for (int name_ = 0; name_ != _numNode; name_++) {
      _nodes.push_back(vector<int>());
      _inDegrees.push_back(0);
    }
  };

  ~Graph() { delete &_nodes; };
  void addEdge(int from, int to) {
    _nodes[from].push_back(to);
    _inDegrees[from]++;
    _numEdge++;
  };

  void printNode() {
    cout << "=============" << endl;
    int i = 0;

    for (auto iter1 : _nodes) {
      cout << i++ << ": ";
      for (auto iter2 : iter1) {
        cout << iter2 << "->";
      }
      cout << endl;
    }
  };
  vector<int> &getInDegree() { return _inDegrees; }

  vector<vector<int>> &getNodes() { return _nodes; }

  int getNumNode() { return _numNode;}

private:
  int _numNode;
  int _numEdge;
  vector<int> _inDegrees;
  vector<vector<int>> _nodes;
};

#endif