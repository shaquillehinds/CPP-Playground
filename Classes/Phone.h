#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Phone{
  public:
    Phone(string phoneName, string phoneOS){
      name = phoneName;
      OS = phoneOS;
    }
    ~Phone(){};

    string GetName(){
      return name;
    }

    string GetOS(){
      return OS;
    }

    void Ring() const {
      cout << "Ring Ring!" << endl;
    }
    void TakePicture()const {
      if(camera) cout << "Click! Picture taken!" << endl;
      else cout << "The " << name << " has no camera!" << endl;
    }
    void FaceTime(string contact)const {
      if(OS == "iOS" && camera) cout << "Facetiming " << contact << endl;
      else{
        if(!camera) cout << "The " << name << " has no camera!" << endl;
        else cout << "The " << name << " is an android device. Facetime is only for iOS devices" << endl;
      }
    }
  private:
    string name;
    bool camera;
    string OS;
};