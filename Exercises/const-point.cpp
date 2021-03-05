int main(){

  // initializes a const variabled
  const int varOne = 6; 

  // initializes a const pointer to the const variable. 
  // Please note that you must specify that the interger will be const// example "const int"
  // Please note that to decalare a const pointer the word const must after the indirection operator or before the pointer name
  const int * const pVarOne = &varOne; 

  return 0;
}