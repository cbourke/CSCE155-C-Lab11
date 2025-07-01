

typedef struct {
  char *id;
  char *locationName;
  double magnitude;
  long timestamp;
  int significance;
  double latitude;
  double longitude;
  double depth; //km
} EarthquakeData;

/**
 *
 */
EarthquakeData *loadData(int *n);

int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth);

char *earthquakeDataToString(EarthquakeData *data);

char *strCopy(const char *str);

void freeEarthquakeData(EarthquakeData *data);
