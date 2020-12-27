# Linked lists

## From 1
* c++ map과 unordered map의 차이
* map : Red-Back tree 기반으로 되어 있어 모든 데이터는 정렬되어 저장됨
  * RB tree : Binary Search Tree에 Self-Balancing되며 기능을 추가한 것으로 AVL Tree만큼 엄격하진 않지만 O(logN)을 보장하는 수준으로 Balancing이 됨
* unordered_map : hash_table 기반의 hash container
  * hash_table을 통해 참조하기 때문에 node 정렬이 필요없음
* 데이터가 많은 경우에는 unordered_map이 map보다 성능면에서 유리
* 문자열을 키로 사용하는 경우 문자열이 길어질수록 unordered_map이 map에 비해 더 성능이 떨어질 수 있음 (길이기 긴 문자열을 hasing하는데 걸리는 시간)
* 유사도가 높은 문자열 집합을 키로 사용하는 경우에 map의 성능이 떨어질 수 있음 (문자열 비교는 문자하나하나 비교하여 크기를 구분하기 때문)
* 결론 : key를 이용하여 정렬을 해야하는 경우를 제외하고 대량의 데이터를 저장할 때는 unordered_map을 사용하는 것이 좋다.

* list가 정렬되어 있으면 unique() 메소드를 통해서 중복 제거가 가능
* container를 loop내에서 지울 때 주의할 점
  * list.erase(iter++)은 iter가 erase()로 복사되어 넘어가고 iter++ 실행되는 것
  * erase(iter++)은 erase(iter)를 지우고 다음 칸으로 가는 것
  * 전위연산자를 쓸 수 있는 상황에서는 항상 쓰는것이 옳다
