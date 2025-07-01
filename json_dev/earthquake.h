

typedef struct {
  char *id;
  char *locationName;
  double magnitude;
  int timestamp;
  double latitude;
  double longitude;
  int depth; //km
} EarthquakeData;

/**
 *
 */
EarthquakeData *loadData(int *n);

initEarthquakeData(EarthquakeData *data);

char *earthquakeDataToString(EarthquakeData *data);

char *strCopy(const char *str);
