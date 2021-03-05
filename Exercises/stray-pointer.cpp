#include <iostream>
/*********Bad Code*********/ //Stray Pointer

// int main()
// {
// int * pVar; // initialised to some random memory address
// *pVar = 9;
// return 0;
// }

/*********Corrected*********/

int main()
{
int varOne;
int * pVar = &varOne;
*pVar = 9;
return 0;
}
