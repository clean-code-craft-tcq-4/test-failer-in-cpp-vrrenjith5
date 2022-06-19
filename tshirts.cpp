#include <iostream>
#include <assert.h>

#define UPPER_BOUNDARY_FOR_SMALL   (38)
#define LOWER_BOUNDARY_FOR_MEDIUM  (39)
#define UPPER_BOUNDARY_FOR_MEDIUM  (41)
#define LOWER_BOUNDARY_FOR_LARGE   (42)

void testForSmall();
void testForMedium();
void testForLarge();

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testForSmall(){
  assert(size(UPPER_BOUNDARY_FOR_SMALL -1) == 'S');
  assert(size(UPPER_BOUNDARY_FOR_SMALL) == 'S');
  assert(size(UPPER_BOUNDARY_FOR_SMALL+1) != 'S');
}

void testForMedium() {
  assert(size(LOWER_BOUNDARY_FOR_MEDIUM -1) != 'M');
  assert(size(LOWER_BOUNDARY_FOR_MEDIUM) == 'M');
  assert(size(UPPER_BOUNDARY_FOR_MEDIUM) == 'M');
  assert(size(UPPER_BOUNDARY_FOR_MEDIUM +1) != 'M');
}

void testForLarge() {
  assert(size(LOWER_BOUNDARY_FOR_LARGE -1) != 'L');
  assert(size(LOWER_BOUNDARY_FOR_LARGE) == 'L');
  assert(size(LOWER_BOUNDARY_FOR_LARGE +1) == 'L');
}

int main() {
    testForSmall();
    testForMedium();
    testForLarge();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
