/* 0 행렬:
 * MxN 행렬의 한 원소가 0일 경우, 해당 원소가 속한 행과 열의 모든 원소를
 * 0으로 설정하는 알고리즘을 작성하라
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void changeRowAndColToZero(vector<vector <int> >& matrix) {
  vector<int> target_row;
  vector<int> target_col;

  for (int row = 0; row < matrix.size(); row++) {
    for (int col = 0; col < matrix[row].size(); col++) {
      if (matrix[row][col] == 0) {
        target_row.emplace_back(row);
        target_col.emplace_back(col);
      }
    }
  }
  for (int row_index : target_row) {
    for (int col = 0; col < matrix[row_index].size(); col++) {
      matrix[row_index][col] = 0;
    }
  }
  for (int col_index : target_col) {
    for (int row = 0; row < matrix.size(); row++) {
      matrix[row][col_index] = 0;
    }
  }
}

int main() {
  vector<vector<int> > matrix;
  vector<int> row1 = {0,2,3,4};
  vector<int> row2 = {5,6,7,8};
  vector<int> row3 = {9,10,11,12};
  vector<int> row4 = {0,14,15,16};

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

  changeRowAndColToZero(matrix); 

  cout << "=============" << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
