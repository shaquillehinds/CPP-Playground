#include <iostream>

int main(){
  unsigned short yourAge;
  unsigned short * pYourAge = &yourAge; 
  *pYourAge = 50;
  std::cout << "yourAge: " << yourAge << std::endl;
  std::cout << "*pYourAge: " << *pYourAge << std::endl;
  delete pYourAge;
  pYourAge = 0;
  return 0;
}