
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// This file shows examples of const parameters, const functions and const return values using references

class SimpleCat{
  
  public:
    // SimpleCat constructor
    SimpleCat(string name);
    // SimpleCat copy constructor
    SimpleCat(SimpleCat&);
    // SimpleCat destructor
    ~SimpleCat();

    // This is not a const function and cannot be called on a const object
    void SetAge(int &num){age = num;}
    // This is a const function and can be called on a const object
    int GetAge()const{return age;}

  private:
    int age;
    string name;

};

SimpleCat::SimpleCat(string CatName){
  cout << "Simple cat constructor" << endl;
  age = 1;
  name = CatName;
}

SimpleCat::SimpleCat(SimpleCat&){
  cout << "Simple cat copy constructor." << endl;
}

SimpleCat::~SimpleCat(){
  cout << "Simple cat desctructor" << endl;
}

//This function takes a reference to the SimpleCat object and treats is like a const object meaning it can't be mutated
//Methods on the SimpleCat object can't be called unless they're are const functions
//This functions returns a reference to a SimpleCat object as a constant
const SimpleCat & FunctionTwo(const SimpleCat & theCat) 
{
 cout << "Function Two. Returning..." << endl;
 cout << "Frisky is now " << theCat.GetAge();
 cout << " years old " << endl;
 // theCat.SetAge(8); const!
 return theCat;
}
int main(){
  
  cout << "Making a cat..." << endl;
  SimpleCat Frisky("Frisky");

  cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;

  int age = 5;
  Frisky.SetAge(age);

  cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;

  cout << "Calling FunctionTwo..." << endl;
  FunctionTwo(Frisky);

  cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
  return 0;

}