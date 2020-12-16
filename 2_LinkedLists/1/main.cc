/* 중복 없애기:
 * 정렬되어 있지 않은 연결리스트가 주어졌을 때 이 리스트에서 중복되는
 * 원소를 제거하는 코드를 작성하라.
 * 임시 버퍼를 사용할 수 없다면 어떻게 풀까? - pointer 두개 사용하여 O(N^2)
 */
#include <iostream>
#include <list>
#include <set>

using namespace std;

void removeDuplication(list<int>& list) {
  set<int> dup_check;
  auto iter = list.begin();

  while (iter != list.end()) {
    if (dup_check.find(*iter) != dup_check.end()) {
      list.erase(iter++);
    } else {
      dup_check.insert(*iter);
      ++iter;
    }
  }

  for (const auto& item : list) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  list<int> list {1,2,4,4,3,4,6};
  removeDuplication(list);

  return 0;
}
