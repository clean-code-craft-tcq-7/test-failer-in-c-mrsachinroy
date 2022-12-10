#include <stdio.h>
#include <assert.h>


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

//Test for return code and counter
void TestRetCode(int Code, int FailCount)
{
    assert((Code != 200) && (FailCount <1));
    assert((Code != 200) || (Code != 500));
}


void alertInCelcius(float farenheit, int (*netAlert)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;

    int returnCode = (*netAlert)(celcius);

    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
    TestRetCode(returnCode,alertFailureCount);
}

int main() {
    alertInCelcius(400.5, &networkAlertStub);
    alertInCelcius(303.6, &networkAlertStub);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
