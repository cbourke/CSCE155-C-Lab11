
#include <json.h>
#include <stdio.h>
#include <string.h>

#include "curl_utils.h"
#include "earthquake.h"

EarthquakeData *loadData(int *n) {

	char *str = getContent(usgs_earthquake_url);

	struct json_object *data;
	data = json_tokener_parse(str);

    struct json_object *metadata = json_object_object_get(data, "metadata");
    struct json_object *count = json_object_object_get(metadata, "count");
    long numDataPoints = json_object_get_int64(count);

    printf("read %ld data points\n", numDataPoints);

    EarthquakeData* result = (EarthquakeData*)malloc(numDataPoints * sizeof(EarthquakeData));

    return result;
}
