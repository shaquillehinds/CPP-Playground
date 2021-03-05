#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class CAT{
  public:
    CAT(int age) {itsAge= age;}
    ~CAT(){}
    int GetAge()const {return itsAge;}
  private:
    int itsAge;
};

/*********************BAD CODE**********************/ //the following create a memory leak

// CAT & MakeCat(int age);

// int main(){

//   int age = 7;
//   CAT Boots = MakeCat(age);
//   cout << "Boots is " << Boots.GetAge() << " years old."<<endl;
  
//   return 0;
// }

// CAT & MakeCat(int age){
//   CAT * pCat = new CAT(age);
//   return *pCat;
// }


CAT * MakeCat(int age);

int main(){

  int age = 7;
  CAT * Boots = MakeCat(age);
  cout << "Boots is " << Boots->GetAge() << " years old."<<endl;
  delete Boots;
  Boots = 0;

  return 0;
}

CAT * MakeCat(int age){
  CAT * pCat = new CAT(age);
  return pCat;
}