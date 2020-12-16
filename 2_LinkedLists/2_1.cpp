#include <list>
#include <string>
#include <algorithm>
using namespace std;

const list<char> removeDuplicatedElem(list<char> li){
  li.sort();
  li.unique();
}

int main(){
  const list<char> li = {'a','q','b','b','c','1','3'};
  auto res = removeDuplicatedElem(li);

  return 0;
}
