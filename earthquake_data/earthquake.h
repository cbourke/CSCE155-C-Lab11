
/**
 * TODO: provide documentation for your structure
 */
typedef struct {
  //TODO: implement
} EarthquakeData;


/**
 * An initialization function to initialize an instance of
 * <code>EarthquakeData</code> with the given values.
 */
int initEarthquakeData(EarthquakeData *data,
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth);

/**
 * A factory function to create an instance of
 * <code>EarthquakeData</code> with the given values.
 */
EarthquakeData *createEarthquakeData(
  const char *id,
  const char *locationName,
  double magnitude,
  int significance,
  long timestamp,
  double latitude,
  double longitude,
  double depth);

/**
 * Loads earthquake data from the given <code>url</code> and returns
 * an array of size <code>n</code>.  Data is assumed to be in the USGS
 * GeoJSON Summary format (see
 * <a href="https://earthquake.usgs.gov/earthquakes/feed/v1.0/geojson.php">here</a>
 * for details).
 *
 */
EarthquakeData *loadEarthquakeData(const char *url, int *n);

/**
 * Parses earthquake data from the given JSON string and returns
 * an array of size <code>n</code>.  Data is assumed to be in the USGS
 * GeoJSON Summary format (see
 * <a href="https://earthquake.usgs.gov/earthquakes/feed/v1.0/geojson.php">here</a>
 * for details).
 */
EarthquakeData *parseEarthquakeData(const char *json_data, int *n);

/**
 * A function to construct a (human-readable) string representation
 * of the given <code>EarthquakeData</code> instance.
 */
char *earthquakeDataToString(const EarthquakeData *data);

/**
 * Prints a human-readable representation of the given
 * <code>EarthquakeData</code> instance to the standard output.
 */
void earthquakeDataPrint(const EarthquakeData *data);

/**
 * Prints human-readable representations (in table format) of the given
 * <code>EarthquakeData</code> instances to the standard output.
 */
void earthquakeDataPrintAll(const EarthquakeData *data, int n);

/**
 * Returns a (deep) copy of the given string.
 */
char *strCopy(const char *str);

/**
 * Runs all reports on the given earthquake data.
 */
void runReports(const EarthquakeData *data, int n);

/**
 * Computes the air distance between the two locations in
 * kilometers.
 */
double airDistance(double originLatitude,
         double originLongitude,
         double destinationLatitude,
         double destinationLongitude);
