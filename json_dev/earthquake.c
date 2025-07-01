
#include <json.h>
#include <stdio.h>
#include <string.h>

#include "curl_utils.h"
#include "earthquake.h"

const char *usgs_earthquake_url = "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_hour.geojson";

EarthquakeData *loadData(int *n) {

	char *str = getContent(usgs_earthquake_url);

	struct json_object *data;
	data = json_tokener_parse(str);

    struct json_object *metadata = json_object_object_get(data, "metadata");
    struct json_object *count = json_object_object_get(metadata, "count");
    long numDataPoints = json_object_get_int64(count);

    printf("read %ld data points\n", numDataPoints);

    EarthquakeData* result = (EarthquakeData*)malloc(numDataPoints * sizeof(EarthquakeData));

    for(int i)

    return result;
}

char *earthquakeDataToString(EarthquakeData *data) {
    char temp[1000];
    sprintf(temp, "%s %s %.1f, (%.2f, %.2f) %d", data->id,
                                  data->locationName,
                                  data->magnitude,
                                  data->latitude,
                                  data->longitude,
                                  data->depth);
    return strCopy(temp);
}

char *strCopy(const char *str) {
    char *copy = (char *) malloc(sizeof(char) * (strlen(str)+1));
    return copy;
}

int initEarthquakeData(EarthquakeData *data) {

}
