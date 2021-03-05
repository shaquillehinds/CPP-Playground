#include "Phone.h"

int main(){

  Phone Redmi("Redmi Note 7", "android");

  Redmi.Ring();
  Redmi.TakePicture();
  Redmi.FaceTime("Patrick");

  return 0;
}