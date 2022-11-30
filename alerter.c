#include <stdio.h>
#include <assert.h>


#define TEST_ENV    (1)
#define PROD_ENV    (2)

#define ENV     TEST_ENV

int alertFailureCount = 0;

//for testing purpose
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

//fucntion for actual network alert
int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
#if ENV == TEST_ENV
    int returnCode = networkAlertStub(celcius);
#elif ENV == PROD_ENV
    int returnCode = networkAlert(celcius);
#endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
#if ENV == TEST_ENV
    assert((returnCode != 200) && (alertFailureCount <1));
#endif
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
