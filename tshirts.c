#include <stdio.h>
#include <assert.h>

#define MAX_SIZE    50
#define MIN_SIZE    25

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

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    for (size_t i = MIN_SIZE; i < MAX_SIZE; i++)
    {
        if(size(i) == '\0')
        {
            assert(0);
        }
    }
    
    printf("All is well (maybe!)\n");
    return 0;
}