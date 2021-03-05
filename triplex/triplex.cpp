#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

bool PlayGameAtDifficulty(int Difficulty);

void PrintIntroduction(int Difficulty);

int main(){

  srand(time(NULL));

  bool Winning = true;

  for(short Difficulty = 1, MaxDifficulty = 10;
    Winning && Difficulty <= MaxDifficulty;
    Winning = PlayGameAtDifficulty(Difficulty), Difficulty++);

  if(Winning){
    cout << "\n\n---------------------------------------------\n\n";
    cout << "Congratulations! You're a triplex master!";
    cout << "\n\n---------------------------------------------\n\n";
  }

  return 0;
}

bool PlayGameAtDifficulty(int Difficulty){

  PrintIntroduction(Difficulty);

  // Declare 3 number code
  const int CodeA = rand() % Difficulty+ Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA+CodeB+CodeC;
  const int CodeProduct = CodeA*CodeB*CodeC;

  cout << endl;
  cout << "+ There are 3 numbers in the code \n";
  cout << "+ The code numbers add-up to: "<< CodeSum << endl;
  cout << "+ The code numbers multiply to give: "<< CodeProduct << endl;
  cout << "+ What are the 3 numbers? \n";
  
  int GuessA, GuessB, GuessC;
  
  cin >> GuessA >> GuessB >> GuessC;
  cout << "You entered: " << GuessA << GuessB << GuessC << endl;

  cin.clear();
  cin.ignore();

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if(GuessSum == CodeSum && GuessProduct == CodeProduct){
    cout << "\n\nYou're a rockstar! \n";
    cout << "Increasing difficulty \n \n \n";
    return true;
  }else{
    cout << "\n\nSorry, unfortunately you got it wrong. \nEnding Game. \n";
    return false;
  }
  
}

void PrintIntroduction(int Difficulty){
  cout << "-------------------------------------------------------\n";
  cout << "You are a secret agent breaking into a level " << Difficulty << " safe" << endl; 
  cout << "You need to enter the correct codes to continue...\n"; 
  cout << "-------------------------------------------------------\n";
}