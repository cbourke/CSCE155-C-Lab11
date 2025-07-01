#include <stdlib.h>
#include <stdio.h>
#include "earthquake.h"

int main(int argc, char **argv) {


    int n;
    EarthquakeData *data = loadData(&n);

    printf("%-15s %-40s %s %s latitude/longitude depth" (%7.2f, %7.2f) %6.2fkm", "Id",
                                  "Location",
                                  "magnitude (significance)",
                                  "time",
                                  time_str,
                                  data->latitude,
                                  data->longitude,
                                  data->depth);
    for(int i=0; i<n; i++) {
        char *s = earthquakeDataToString(&data[i]);
        printf("%s\n", s);
        freeEarthquakeData(&data[i]);
    }
    free(data);

    return 0;
}
