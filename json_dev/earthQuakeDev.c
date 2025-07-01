#include <stdlib.h>
#include <stdio.h>
#include "earthquake.h"

int main(int argc, char **argv) {


    int n;
    EarthquakeData *data = loadData(&n);
    for(int i=0; i<n; i++) {
        char *s = earthquakeDataToString(&data[i]);
        printf("%s\n", s);
    }


    return 0;
}
