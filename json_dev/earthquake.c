
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

    struct json_object *features_obj = json_object_object_get(data, "features");
    //struct array_list *features = json_object_get_array(features_obj);
    int length = json_object_array_length(features_obj);
    for(int i=0; i<length; i++) {
        struct json_object *feature = json_object_array_get_idx(features_obj, i);
        //features[i].id
        const char *id = json_object_get_string(json_object_object_get(feature, "id"));
        //features[i].properties
        struct json_object *properties = json_object_object_get(feature, "properties");
        const char *locationName = json_object_get_string(json_object_object_get(properties, "place"));
        double magnitude = json_object_get_double(json_object_object_get(properties, "mag"));
        int timestamp = json_object_get_double(json_object_object_get(properties, "time"));

        //features[i].geometry.coordinates
        struct json_object *coordinates = json_object_object_get(feature, "geometry.coordinates");
        double latitude = json_object_get_double(json_object_array_get_idx(coordinates));


        initEarthquakeData(&result[i], id, locationName, magnitude, timestamp, 0, 0, 0);
    }




    return result;
}

char *earthquakeDataToString(EarthquakeData *data) {
    char temp[1000];
    sprintf(temp, "%10s %-40s %.1f, (%.2f, %.2f) %d", data->id,
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

int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int timestamp,
  double latitude,
  double longitude,
  int depth) {

    data->id = strCopy(id);
    data->locationName = strCopy(locationName);
    data->magnitude = magnitude;
    data->timestamp = timestamp;
    data->latitude = latitude;
    data->longitude = longitude;
    data->depth = depth;

    return 0;
}

void freeEarthquakeData(EarthquakeData *data) {
    free(data->id);
    free(data->locationName);
    return;
}
