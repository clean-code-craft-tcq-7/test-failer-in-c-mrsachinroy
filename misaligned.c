#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    
    printf("All is well (maybe!!!!!!!!!!======!!!!!!)\n");
    FILE *ClrMapOut = freopen("output.txt", "w", stdout);
    int result = printColorMap();
    fclose(ClrMapOut);
    // fflush( stdout );
    
    printf("All is well =============================================(maybe!)\n");
    fclose(stdout);
    
    printf("All is well =============================================(maybe!)\n");
    setvbuf (stdout, NULL, _IONBF, 0);
    assert(result == 5);
    printf("All is well =============================================(maybe!)\n");

    return 0;
}