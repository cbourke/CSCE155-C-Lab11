#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <string.h>
#include <time.h>

#include <json.h>

#include "utils/curl_utils.h"

#include "earthquake.h"

int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth) {

    //TODO: implement

    return 0;
}

EarthquakeData * createEarthquakeData(
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth) {
    //TODO: implement
}

EarthquakeData *parseEarthquakeData(const char *json_data, int *n) {

    struct json_object *data;
	data = json_tokener_parse(json_data);

    struct json_object *metadata = json_object_object_get(data, "metadata");
    struct json_object *count = json_object_object_get(metadata, "count");
    long numDataPoints = json_object_get_int64(count);
    *n = numDataPoints;

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

        struct json_object *place = json_object_object_get(properties, "place");
        const char *locationName = json_object_get_string(place);
        double magnitude = json_object_get_double(json_object_object_get(properties, "mag"));
        int significance = json_object_get_int(json_object_object_get(properties, "sig"));
        long timestamp = json_object_get_int64(json_object_object_get(properties, "time"));

        //features[i].geometry.coordinates
        struct json_object *coordinates = json_object_object_get(json_object_object_get(feature, "geometry"), "coordinates");
        double latitude = json_object_get_double(json_object_array_get_idx(coordinates, 1));
        double longitude = json_object_get_double(json_object_array_get_idx(coordinates, 0));
        double depth = json_object_get_double(json_object_array_get_idx(coordinates, 2));

        initEarthquakeData(&result[i], id, locationName, magnitude, significance, timestamp, latitude, longitude, depth);
    }

    json_object_put(data);

    return result;
}

EarthquakeData *loadEarthquakeData(const char *url, int *n) {

	char *str = getContent(url);
    EarthquakeData *result = parseEarthquakeData(str, n);
    free(str);
    return result;
}


char *earthquakeDataToString(const EarthquakeData *data) {

    //this code converts the data's timestamp to a human-readable format
    // you may need to modify this depending on what you named your field(s)
    time_t timestamp_s = data->timestamp / 1000; // Convert to seconds

    struct tm *timeinfo = gmtime(&timestamp_s); // For UTC
    char time_str[30];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S UTC", timeinfo);

    //TODO: implement

}


void earthquakeDataPrint(const EarthquakeData *data) {
    char *str = earthquakeDataToString(data);
    printf("%s\n", str);
    free(str);
    return;
}

void earthquakeDataPrintAll(const EarthquakeData *data, int n) {
    printf("Earthquake Data (n = %d)\n", n);
    printf("%-15s %-39s %s %24s %20s %8s\n", "Id",
                                  "Location",
                                  "magnitude/(sig)",
                                  "time",
                                  "lat/lon", "depth");
    for(int i=0; i<n; i++) {
        earthquakeDataPrint(&data[i]);
    }
    printf("\n\n");
}


char *strCopy(const char *str) {
    char *copy = (char *) malloc(sizeof(char) * (strlen(str)+1));
    strcpy(copy, str);
    return copy;
}

void runReports(const EarthquakeData *data, int n) {

    //find the minimum magnitude earthquake and print it
    int minMagnitudeIndex = 0;
    for(int i=1; i<n; i++) {
        if(data[i].magnitude < data[minMagnitudeIndex].magnitude) {
            minMagnitudeIndex = i;
        }
    }
    printf("Weakest Magnitude Earthquake: \n");
    earthquakeDataPrint(&data[minMagnitudeIndex]);

    //find the maximum magnitude earthquake and print it
    //but use a pointer instead of an index
    const EarthquakeData *maxMagnitudeEarthquake = &data[0];
    for(int i=1; i<n; i++) {
        if(data[i].magnitude > maxMagnitudeEarthquake->magnitude) {
            maxMagnitudeEarthquake = &data[i];
        }
    }
    printf("Strongest Magnitude Earthquake: \n");
    earthquakeDataPrint(maxMagnitudeEarthquake);

    //find the closest earthquake to Lincoln, NE, 40.806862, -96.681679
    //TODO: implement
   printf("Closest Earthquake to Lincoln (%f kms away): \n", minDistance);


}

double airDistance(double originLatitude,
         double originLongitude,
         double destinationLatitude,
         double destinationLongitude) {

  originLatitude = originLatitude * M_PI / 180;
  originLongitude = originLongitude * M_PI / 180;
  destinationLatitude = destinationLatitude * M_PI / 180;
  destinationLongitude = destinationLongitude * M_PI / 180;

  double distance = acos(sin(originLatitude) * sin(destinationLatitude) + cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude-originLongitude)) * 6371.0;
  return distance;
}
