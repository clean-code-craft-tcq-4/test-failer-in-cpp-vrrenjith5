#include <iostream>
#include <assert.h>

#define ALERT_NOT_REQUIRED      (200)
#define ALERT_REQUIRED          (500)

int alertFailureCount = 0;

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

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != ALERT_NOT_REQUIRED) {
        std::cout << "returnCode is : " <<returnCode<<std::endl;
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(450.6);
    alertInCelcius(420.6);
    if (alertFailureCount == 3) {
      std::cout <<" Alerts count is success, count is: "<<alertFailureCount<<std::endl;
    }
    else {
      std::cout <<" Alerts count is failed, count is: "<<alertFailureCount<<std::endl;
    }
    assert(alertFailureCount == 3);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
