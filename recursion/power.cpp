#include <iostream>

using std::cout;
using std::cin;

int main(){
  int PowerOf(int Num, int Power);

  cout << "Please enter two numbers.\n";
  cout << "The first is the number you want to find the power of and the second number is the power. \n";
  int Num, Power;
  cin >> Num;
  cin >> Power;

  const int Answer = PowerOf(Num, Power);
  cout << Answer;
}


int PowerOf(int N, int P){
  if(P == 1) return N;
  int Answer = PowerOf(N, P-1) * N;
  return Answer;
}