
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
    *n = numDataPoints;

    printf("read %ld data points\n", numDataPoints);

    EarthquakeData* result = (EarthquakeData*)malloc(numDataPoints * sizeof(EarthquakeData));

    for(int i=0; i<numDataPoints; i++) {
        initEarthquakeData(&result[i]);
    }

    struct json_object *features_obj = json_object_object_get(metadata, "features");
    struct array_list *features = json_object_get_array(features_obj);
    int length = json_object_array_length(features_obj);
    for(int i=0; i<length; i++) {
        struct json_object *feature = json_object_array_get_idx(features_obj, i);
        printf("debug: %d...\n", i);
    }




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
    strcpy(copy, str);
    return copy;
}

int initEarthquakeData(EarthquakeData *data) {

    data->id = strCopy("TEST_ID");
    data->locationName = strCopy("TEST_LOC");
    data->magnitude = 10;
    data->timestamp = 100;
    data->latitude = 4.5;
    data->longitude = 3.5;
    data->depth = 32;

    return 0;
}
