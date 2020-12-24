/* 동물 보호소:
 * 먼저 들어온 동물이 먼저 나가는 동물 보호소가 있다고 하자.
 * 이 보호소는 개와 고양이만 수용한다. 사람들은 보호소에서 가장 오래된 동물부터
 * 입양할 수 있는데, 개와 고양이 중 어떤 동물을 데려갈지 선택할 수 있다.
 * 하지만 특정한 동물을 지정해 데려갈 수 는 없다.
 * 이 시스템을 자료구조로 구현하라. 이 자료구조는 enqueue, dequeueAny,
 * dequeueDog, dequeueCat의 연산을 제공해야 한다. 기본적으로 탑재되어 있는
 * LinkedList 자료구조를 사용해도 좋다.
 */
#include "../stack.h"
#include <vector>

constexpr int CAPACITY = 8;

using namespace std;
class Queue {
 public:
  Queue() 
      : front_(0), size_(0) {}
  ~Queue() {}

  void enqueue(string name) {
    if (size_ == CAPACITY) {
      cout << "queue is full" << endl;
      return;
    }
    list_.push_back({name, sequence_++});
    ++size_;
  }

  pair<string, int> dequeue() {
    if (!size_) {
      return {"",0};
    }
    --size_;
    return list_[front_++];
  }

  pair<string, int> front() {
    return list_[front_];
  }

 private:
  static int sequence_;

  vector<pair<string, int>> list_;
  int front_;
  int size_;
};

int Queue::sequence_ = 0;

class AnimalQueue {
 public:
  AnimalQueue()
      : sequence_(0) {}
  ~AnimalQueue() {}

  void enqueue(string type, string name) {
    if (type == "dog") {
      dogs_.enqueue(name);
    } else if (type == "cat") {
      cats_.enqueue(name);
    } else {
      cout << "Refused" << endl;
    }
  }

  string dequeueAny() {
    if (dogs_.front().second < cats_.front().second) {
      return dogs_.dequeue().first;
    } else {
      return cats_.dequeue().first;
    }
  }

  string dequeueDog() {
    return dogs_.dequeue().first;
  }

  string dequeueCat() {
    return cats_.dequeue().first;
  }

 private:
  Queue dogs_, cats_;
  int sequence_;
};

int main() {
  AnimalQueue aq;
  aq.enqueue("dog", "dog1");
  aq.enqueue("cat", "cat1");
  aq.enqueue("dog", "dog2");
  aq.enqueue("dog", "dog3");
  aq.enqueue("cat", "cat2");

  cout << aq.dequeueAny() << endl;
  cout << aq.dequeueDog() << endl;
  cout << aq.dequeueCat() << endl;
  return 0;
}
