#include <stdlib.h>
#include <stdio.h>
#include "earthquake.h"

int main(int argc, char **argv) {


    int n;
    EarthquakeData *data = loadData(&n);

    printf("%-15s %-40s %s %s latitude/longitude depth", "Id",
                                  "Location",
                                  "magnitude (significance)",
                                  "time");
    for(int i=0; i<n; i++) {
        char *s = earthquakeDataToString(&data[i]);
        printf("%s\n", s);
        freeEarthquakeData(&data[i]);
    }
    free(data);

    return 0;
}
