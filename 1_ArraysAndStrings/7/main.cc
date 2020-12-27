/* 행렬 회전:
 * 이미지를 표현하는 NxN 행렬이 있다. 이미지의 각 픽셀은 4바이트로 표현된다.
 * 이때, 이미지를 90도 회전시키는 메서드를 작성하라.
 * 행렬을 추가로 사용하지 않고서도 할 수 있겠는가?
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool rotate(vector<vector<int> >& matrix) {
  if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
    return false;
  }
  int n = matrix.size();
  for (int layer = 0; layer < n/2; layer++) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; i++) {
      int offset = i - first;
      int top = matrix[first][i];

      matrix[first][i] = matrix[last-offset][first];
      matrix[last-offset][first] = matrix[last][last-offset];
      matrix[last][last-offset] = matrix[i][last];
      matrix[i][last] = top;
    }
  }
  return true;
}

int main() {
  vector<vector<int> > matrix;
  vector<int> row1 = {1,2,3,4};
  vector<int> row2 = {5,6,7,8};
  vector<int> row3 = {9,10,11,12};
  vector<int> row4 = {13,14,15,16};

  matrix.emplace_back(row1);
  matrix.emplace_back(row2);
  matrix.emplace_back(row3);
  matrix.emplace_back(row4);

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  if (!rotate(matrix)) {
    cout << "failed to rotate" << endl;
    return 1;
  }

  cout << "after rotation" << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
