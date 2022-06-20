#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
char previousMinorColor[] = "defaultMinor";

int printColorMap() {
  int i = 0, j = 0;
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";

      int returnMinor = strcmp(previousMinorColor, minorColor[i]);
      if (0 == returnMinor) {
        std::cout<<"Error : Minor Strings are equal"<<endl;
        return i * j;
      }
      else {
        std::cout<<"Succes : Minor Strings are unequal"<<endl;
      }
      strcpy(previousMinorColor, minorColor[i]);
    }
  }
  return i * j;
}

int main() {
  int result = printColorMap();
  assert(result == 25);
  std::cout << "All is well (maybe!)\n";
  return 0;
}
