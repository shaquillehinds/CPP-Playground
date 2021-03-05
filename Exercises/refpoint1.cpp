#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){

  int myNum = 5;
  int & rMyNum = myNum;
  int * pMyNum = &myNum;
  
  cout << "mNum: " << myNum << endl;

  rMyNum = 10;
  cout << "rMyNum = 10"<< endl;
  cout << "myNum: " << myNum << endl;

  *pMyNum = 20;
  cout << "*pMyNum = 20"<< endl;
  cout << "myNum: " << myNum << endl;

  return 0;
}