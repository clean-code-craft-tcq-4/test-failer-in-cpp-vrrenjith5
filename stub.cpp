#include <iostream>
#include <assert.h>
#include "stub.h"

#define ALERT_NOT_REQUIRED      (200)
#define ALERT_REQUIRED          (500)

int networkAlertStub(float celcius) {
    int alertReturn = ALERT_NOT_REQUIRED;
    if (celcius > ALERT_NOT_REQUIRED) {
      std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
      // Return 200 for ok
      // Return 500 for not-ok
      // stub always succeeds and returns 200
      alertReturn = ALERT_REQUIRED;
    }
    return alertReturn;
}
