#include <iomanip>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#define PIN_INFO "Pin No. "

using namespace std;
std::vector< std::string > colorCoderPair;
std::vector< std::string > expectedColorCoderPair;

void getColorPair();
void printColorMap();
void testForColorCoderLengh();
void testForDuplicatesInColorCoder();
void testColorCoderPairWithExpected(int pairNumberIndex, std::string expectedColorPair);
void expectedColorPair();

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
      colorPairStr += "/";
      colorPairStr += minorColor[minorColorIterator];
      colorCoderPair.push_back(colorPairStr);
    }
  }
}

void printColorMap() {
  getColorPair();
  for(int colorCodeIndex =0; colorCodeIndex < colorCoderLength; colorCodeIndex++) {
    if(colorCodeIndex < 9) {
       std::cout<< PIN_INFO << colorCodeIndex + 1 <<std::setw(4)<< " | " << colorCoderPair[colorCodeIndex] <<std::setw(5) << "\n";
    }
    else {
       std::cout<< PIN_INFO << colorCodeIndex + 1 <<std::setw(3)<< " | " << colorCoderPair[colorCodeIndex] <<std::setw(5) << "\n";
    }
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

void testColorCoderPairWithExpected(int pairNumberIndex, std::string expectedColorPair) {
  assert(colorCoderPair[pairNumberIndex] == expectedColorPair);
}

void expectedColorPair(){
  expectedColorCoderPair.push_back("White/Blue");
  expectedColorCoderPair.push_back("White/Orange");
  expectedColorCoderPair.push_back("White/Green");
  expectedColorCoderPair.push_back("White/Brown");
  expectedColorCoderPair.push_back("White/Slate");
  expectedColorCoderPair.push_back("Red/Blue");
  expectedColorCoderPair.push_back("Red/Orange");
  expectedColorCoderPair.push_back("Red/Green");
  expectedColorCoderPair.push_back("Red/Brown");
  expectedColorCoderPair.push_back("Red/Slate");
  expectedColorCoderPair.push_back("Black/Blue");
  expectedColorCoderPair.push_back("Black/Orange");
  expectedColorCoderPair.push_back("Black/Green");
  expectedColorCoderPair.push_back("Black/Brown");
  expectedColorCoderPair.push_back("Black/Slate");
  expectedColorCoderPair.push_back("Yellow/Blue");
  expectedColorCoderPair.push_back("Yellow/Orange");
  expectedColorCoderPair.push_back("Yellow/Green");
  expectedColorCoderPair.push_back("Yellow/Brown");
  expectedColorCoderPair.push_back("Yellow/Slate");
  expectedColorCoderPair.push_back("Violet/Blue");
  expectedColorCoderPair.push_back("Violet/Orange");
  expectedColorCoderPair.push_back("Violet/Green");
  expectedColorCoderPair.push_back("Violet/Brown");
  expectedColorCoderPair.push_back("Violet/Slate");
}

int main() {
  expectedColorPair();
  printColorMap();
  testForColorCoderLengh();
  testForDuplicatesInColorCoder();
  for(int colorCodeCounter = 0; colorCodeCounter < colorCoderLength ;colorCodeCounter++) {
    testColorCoderPairWithExpected(colorCodeCounter, expectedColorCoderPair[colorCodeCounter]);
  }
  std::cout << "All is well\n";
  return 0;
}
