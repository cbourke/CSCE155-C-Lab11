
/**
 * Types of supported RSS Feeds
 */
typedef enum {
  RSS2,
  ATOM1
} Version;

/**
 * Data associated with an RSS Service
 */
typedef struct {
  char *name;
  char *url;
  Version type;
} RssService;

/**
 * RSS feed for the School of Computing's weekly
 * Bits and Bytes newsletter
 */
static const RssService cseBitsAndBytes = {
    "SoC Bits and Bytes",
    "https://newsroom.unl.edu/announce/cse/?format=rss",
    RSS2
};

/**
 * RSS feed for Husker athletics news
 */
static const RssService huskerNews = {
    "Husker Sports News",
    "https://huskers.com/rss.aspx",
    RSS2
};

/**
 * RSS feed for the University of Nebraska-Omaha
 */
static const RssService unoNews = {
    "University of Nebraska-Omaha",
    "https://www.unomaha.edu/news/index.rss",
    RSS2
};

/**
 * An RSS feed of Reddit's front page.
 */
static const RssService reddit = {
  "Reddit",
  "https://www.reddit.com/.rss",
  ATOM1};

/**
 * A utility function to parse an XML feed from an RSS feed
 */
void parseRssXml(xmlNode *rootNode);

/**
 * A utility function to parse an XML feed from an Atom feed
 */
void parseAtomXml(xmlNode *rootNode);
