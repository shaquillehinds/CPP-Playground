#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// This file shows const parameters, const functions and const return values using pointers
// Note that to declare a pointer as a constant, the const keyword must come after the pointer

class Cat{
  public:
    Cat(string newName);
    Cat(Cat&);
    ~Cat();

    void SetAge(int num){
      age = num;
    }
    int GetAge()const{
      return age;
    }
    string GetName()const{
      return name;
    }
  private:
    int age;
    string name;


};

Cat::Cat(string newName){
  name = newName;
  age = 1;
  cout << "Constructor Called! Your new name is "<< name << " and you are "<< age << " year old."<<endl;
}
Cat::Cat(Cat&){
  cout << "Copy cnstructor Called! Your name is "<< name << " and you are "<< age << " year(s) old."<<endl;
}
Cat::~Cat(){
  cout << "Desctructor called" << endl;
}

// This function takes a pointer to a Cat object and the pointer is treated as a const it can't be changed
// Please note that Cat is not declared as constant only the pointer so the Cat can be mutated
// This functions returns a const pointer to a Cat object and the return Cat object is declared as constant
const Cat * const FunctionOne(Cat * const theCat);

// This function takes a pointer to a const Cat object and the pointer is treated as a const it can't be changed
// Since the cat is also declared as a const, it can't be mutated. Only const methods on the object can be called
// This functions returns a const pointer to a constant Cat object
const Cat * const FunctionTwo(const Cat * const theCat);

int main(){

  cout << "Making a cat..." << endl;
  Cat Coco("Coco");

  cout << "Coco is " << Coco.GetAge() << " years old" << endl;

  int age = 5;
  Coco.SetAge(age);

  cout << "Coco is " << Coco.GetAge() << " years old" << endl;

  cout << "Calling FunctionTwo..." << endl;
  Cat * const pCoco = &Coco;

  // Here I decided to play with parameters and return types 
  // Function one takes a pointer to a cat object but function two takes a pointer to a constant cat object
  // So I created a constant pointer to Coco and named it pCoco and passed it to functionOne
  // Then I made functionOne return a constant pointer to a Cat object but make the Cat object a constant
  // IMPORTANT!! A cat is only treated as constant inside of the function! This does not change the type of the Cat on the global scope
  // If you return the pointer to the constant object, only that return value(object) will be treated as a constant
  const Cat * pCopy = FunctionTwo(FunctionOne(pCoco));

  cout << "Coco is " << Coco.GetAge() << " years old" << endl;

  cout << "Coco is now " << Coco.GetAge() << " years old" << endl;

  //delete pointer and set it to null
  delete pCoco;
  // pCoco = 0; // cannot reassign when pointer is a constant

  return 0;
}

const Cat * const FunctionOne(Cat * const theCat){
  // this pointer can still be modified if not explicitely declared as constant in the function parameters
  // theCat = 0; 
  cout << "Function One. Returning..." << endl;
  theCat->SetAge(8);
  cout << theCat->GetName() << " is now " << theCat->GetAge() << " years old.\n";
  return theCat;
}

const Cat * const FunctionTwo(const Cat * const theCat){
  cout << "Function Two. Returning..." << endl;
  cout << theCat->GetName() << " is now " << theCat->GetAge();
  cout << " years old " << endl;
  // theCat->SetAge(8); const!
  return theCat;
}