#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;
std::vector< std::string > colorCoderPair;

void getColorPair();
int printColorMap();
void testForColorCoderLengh();
void testForDuplicatesInColorCoder();
void testColorCoderPair(int pairNumber, std::string expectedColorPair);

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
const int colorCoderLength = numberOfMajorColors * numberOfMinorColors;

void getColorPair(){
  int majorColorIterator = 0, minorColorIterator = 0;
  for(majorColorIterator = 0; majorColorIterator < numberOfMajorColors; majorColorIterator++) {
    for(minorColorIterator = 0; minorColorIterator < numberOfMinorColors; minorColorIterator++) {
      std::string colorPairStr = majorColor[majorColorIterator];
      colorPairStr += " | ";
      colorPairStr += minorColor[majorColorIterator];
      colorCoderPair.push_back(colorPairStr);
    }
  }
}

int printColorMap() {
  getColorPair();
  for(int i=0; i<colorCoderLength; i++) {
    std::cout<< i + 1 << " | " << colorCoderPair[i] << "\n";
  }
}

void testForColorCoderLengh() {
  int actualLength = colorCoderPair.size();
  assert(actualLength == colorCoderLength);
}

void testForDuplicatesInColorCoder() {
  std::set<std::string> s(colorCoderPair.begin(), colorCoderPair.end());
  assert(s.size() == colorCoderPair.size());
}

void testColorCoderPair(int pairNumber, std::string expectedColorPair) {
  int pairNumberInZeroBased = pairNumber - 1;
  assert(colorCoderPair[pairNumberInZeroBased] == expectedColorPair);
}

int main() {
  int result = printColorMap();
  testForColorCoderLengh();
  testForDuplicatesInColorCoder();
  testColorCoderPair(20, "Yellow | Slate");
  testColorCoderPair(1, "White | Blue");
  std::cout << "All is well (maybe!)\n";
  return 0;
}
