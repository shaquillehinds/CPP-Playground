#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int num = 5;
  cout << "creating reference\n";
  cout << "int &rNum = num;\n";
  int &rNum = num;
  cout << "num: " << num << endl;
  cout << "rNum: " << rNum << endl;
  num = 10;
  cout << "num = 10;" << endl;
  cout << "num: " << num << endl;
  cout << "rNum: " << rNum << endl;
  rNum = 20;
  cout << "rNum = 20;" << endl;
  cout << "num: " << num << endl;
  cout << "rNum: " << rNum << endl;

}