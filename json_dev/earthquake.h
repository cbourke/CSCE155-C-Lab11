

typedef struct {
  char *id;
  char *locationName;
  double magnitude;
  int timestamp;
  double latitude;
  double longitude;
  int depth; //km
} EarthquakeData;

const char *usgs_earthquake_url = "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_hour.geojson";

/**
 *
 */
EarthquakeData *loadData(int *n);
