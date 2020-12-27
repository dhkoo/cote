/* 동물 보호소 
* 개와 고양이만 수용 할 수 있는 보호소를 표현할 수 있는 자료 구조 작성
* push, pop, popCat, popDog 해줘야함
*/

#include <string>
#include <queue>

using namespace std;
class Animal{
public:
  Animal(){}
  Animal(string type){
    kind_ = type;
  };
  ~Animal(){};

  string getKind(){return kind_;}

private: 
  string kind_;
};

void push(queue<Animal>& shelter, Animal& animal){
  shelter.push(animal);
};

Animal popAny(queue<Animal>& shelter){
  Animal res = shelter.front();
  shelter.pop();
  return res;
};

Animal popCat(queue<Animal>& shelter){
  return popKind(shelter, "Cat");
};

Animal popDog(queue<Animal>& shelter){
  return popKind(shelter, "Dog");

};

Animal popKind(queue<Animal>& shelter, string kind){
  queue<Animal> tempShelter;
  Animal res;

  while(shelter.empty()){
    Animal temp = shelter.front();
    shelter.pop();

    if(temp.getKind()==kind){
      res=temp;
      break;
    }
    else {
      tempShelter.push(temp);
    }
  }
  while(tempShelter.empty()){
    Animal temp = tempShelter.front();
    tempShelter.pop();
    shelter.push(temp);
  }

  return res;
};

