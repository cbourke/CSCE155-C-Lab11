

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

int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int timestamp,
  double latitude,
  double longitude,
  int depth);

char *earthquakeDataToString(EarthquakeData *data);

char *strCopy(const char *str);

void freeEarthquakeData(EarthquakeData *data);
