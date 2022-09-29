# Computer Science I
## Lab 11.0 - Encapsulation & Structures
[School of Computing](https://computing.unl.edu)  
[College of Engineering](https://engineering.unl.edu/)  
[University of Nebraska-Lincoln](https://unl.edu)  
[University of Nebraska-Omaha](https://unomaha.edu)  

This lab introduces encapsulation and structures in C.

## Prior to Lab

* Read and familiarize yourself with this handout.
* Read the required chapters(s) of the textbook as
  outlined in the course schedule.

In addition, you may want to:

* Read Chapters 10 and 23 of the [Computer Science I](http://cse.unl.edu/~cbourke/ComputerScienceOne.pdf) textbook
* Watch Videos 11.1 thru 11.3 of the [Computer Science I](https://www.youtube.com/playlist?list=PL4IH6CVPpTZVkiEnCEOdGbYsFEdtKc5Bx)
  video series

### Peer Programming Pair-Up

**For students in the online section:** you may complete the lab on your
own if you wish or you may team up with a partner of your choosing.  You
may consult with a lab instructor to get teamed up online (via Zoom).

**For students in the face-to-face section:** your lab instructor will
team you up with a partner.

To encourage collaboration and a team environment, labs are be
structured in a *peer programming* setup. At the start of each lab, you
will be randomly paired up with another student (conflicts such as
absences will be dealt with by the lab instructor). One of you will be
designated the *driver* and the other the *navigator*.

The navigator will be responsible for reading the instructions and
telling the driver what to do next. The driver will be in charge of the
keyboard and workstation. Both driver and navigator are responsible for
suggesting fixes and solutions together. Neither the navigator nor the
driver is "in charge." Beyond your immediate pairing, you are encouraged
to help and interact and with other pairs in the lab.

Each week you should alternate: if you were a driver last week, be a
navigator next, etc. Resolve any issues (you were both drivers last
week) within your pair. Ask the lab instructor to resolve issues only
when you cannot come to a consensus.

Because of the peer programming setup of labs, it is absolutely
essential that you complete any pre-lab activities and familiarize
yourself with the handouts prior to coming to lab. Failure to do so will
negatively impact your ability to collaborate and work with others which
may mean that you will not be able to complete the lab.

### Lab Objectives & Topics

At the end of this lab you should be familiar with the following

-   Be familiar with the concepts of encapsulation & modularity

-   Understand how to design, declare, and use C structures (both by
    reference and by value)

-   Have some exposure to advanced topics such as sockets, the HTTP
    protocol, and XML processing

## 2. Background

### 2.1 RSS Feeds

An RSS feed (RDF Site Summary or "Really Simple Syndication") is a
format used to publish frequently updated works. RSS enabled clients can
subscribe to RSS feeds and update a user as to new or relevant news
items. RSS feeds are most commonly formatted using XML (Extensible
Markup Language) that use XML tags to indicate what the data represents
(the title of the article, a short description, etc.). Clients "read" an
RSS feed by making a connection to a server using the HyperText Transfer
Protocol (HTTP).

For example, UNL has an RSS news feed available at
<http://newsroom.unl.edu/releases/?format=xml> which serves XML data
that looks something like the following:

```xml
<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">
<channel>
  <title>UNL News Releases</title>
  <link>http://newsroom.unl.edu/releases/</link>
  <description>News from the University of Nebraska-Lincoln</description>
  <language>en-us</language>
  <copyright>Copyright 2012 University of Nebraska-Lincoln</copyright>
  <image>
    <title>UNL News Releases</title>
    <url>http://www.unl.edu/favicon.ico</url>
    <link>http://www.unl.edu/</link>
  </image>
  <item>
    <title>Guerrilla Girls on Tour perform 'Feminists are Funny' Monday at Sheldon</title>
    <link>http://newsroom.unl.edu/releases/2012/03/09/Guerrilla</link>
    <description>The Guerrilla Girls on Tour, an internationally acclaimed anonymous theater collective, will perform "Feminists are Funny" at the University of Nebraska-Lincoln's Sheldon Museum of Art, 12th and R streets, at 7 p.m. March 12. The 70-minute play is an...
    </description>
    <pubDate>Fri, 09 Mar 2012 02:00:00 -0600</pubDate>
  </item>
  ...
  </items>
</channel>
```

### 2.2 Structures in C

An entity may be composed of several different pieces of data. A person
for example may have a first and last name (strings), an age (integer),
a birthdate (some date/time representation), etc. Its much easier and
more natural to group each of these pieces of data into one entity. This
is a concept known as *encapsulation*--a mechanism by which data can be
grouped together to define an entity.

The C programming language provides a mechanism to achieve encapsulation
using structures. Structures are user defined types that have one or
more data fields–variables which have a type and a name. To access the
member fields of a structure you can use the dot operator; example: .
`student.firstName`.  However, when you have a reference (pointer) to a
structure, you need to use the arrow operator: `student->firstName`.

### 2.3 RSS Client Background

You have been provided with an incomplete RSS client written in C. The
client uses the cURL library (Client URL) library to make an HTTP
(or a secure HTTPS) connection using a URL (a web address) to an RSS
server.  The server responds with a stream of data that
the client reads into a buffer. This data stream can, in general, be any
type of data, but we're expecting an RSS feed--a stream of plain text
XML-formatted data conforming to the RSS standard. Since the data is
plain text, it is stored in a character array which is then handed off
to another function to parse the XML document. This is done using an XML
library (libxml2, an XML parser and toolkit for Gnome).

## 3. Activities

### 3.1 Getting Started

Clone the project code for this lab from GitHub by using the following
URL: <https://github.com/cbourke/CSCE155-C-Lab11>.

In addition, you may need to install some libraries to complete this
activity.  Run the following command:

`sudo apt-get install libcurl4-gnutls-dev`

### 3.2 `Student` Structure Demo

To demonstrate how to define and use a structure, we have provided a
completed program (see the files in the `studentDemo` directory)
with a full structure definition to model a student.
Several functions have been implemented to assist in the construction
and printing of this structure. In particular there are two "factory"
functions that can be used to help in the construction of an individual
structure. The factory function takes the appropriate parameters, allocates
memory for a new `Student` instance and sets each field of the structure
appropriately. In the case of strings, `malloc` is used to create enough
space and the string is then copied. The `birthDate` is handled specially:
it parses the date string and creates a `struct tm` which is a *time* structure
defined by the time library (`time.h`). Finally, a pointer to the new
`Student` structure is returned. There is also a print function that takes
a student (by reference) and prints it out to the standard output.

#### Instructions

1.  Examine the syntax and program structure and observe how each
    factory function works as well as how they are used.

2.  Change the values in the function to your name, NUID, and birth
    date.

3.  Compile and run the program using the following commands.

    ```text
    gcc -c student.c
    gcc student.o studentDemo.c
    ```
    Run your program and observe the results. Refer back to this
    program in the next activity as needed.

### 3.3 Completing the RSS Client

In this activity, you will complete the RSS Client that connects to a
UNL RSS feed, processes the XML data and outputs the results to the
standard output. Most of the client has been completed for you. You just
need to complete the design and implementation of a C structure that
models the essential parts of an RSS "item" (usually an individual
news story). Your structure will need to support an RSS item's title,
link, description, and publication date.

To keep things simple, we recommend that you represent the date using a
string. If you would like to try using the structure defined in the time
library, you may find the following documentation useful:
<http://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html>
<https://pubs.opengroup.org/onlinepubs/7908799/xsh/strptime.html>

#### Instructions

1.  Go to the `rss` directory.  We have provided a collection of source
    files to do most of the work for you.  To compile it, we have provided
    a `makefile`.  Simply type `make` and it produces an executable called
    `runRss`.

2.  Examine the `main` function in `runRss.c` and observe how to use
    the program to connect to three different RSS feeds using
    command line arguments.

3.  Design and implement the RSS structure in the `rss.h` header file

4.  Complete all the functions as specified in their documentation.


## 4. Handin/Grader Instructions

1.  Hand in your completed files:

    - `rss.h`
    - `rss.c`

    through the handin and verify it compiles and works through the
    grader.

2.  Even if you worked with a partner, you *both* should turn in all
    files.

## Advanced Activity (Optional)

1.  You will notice that internally, we have provided support for both
    RSS 2.0 feeds and Atom 1.0 feeds (Reddit uses Atom for example).
    Examine the files where we have defined these feeds. Find an RSS or
    Atom feed that is of interest to you and integrate it as an option
    for this program. Be sure to update the `main` function so that it can
    be used.

2.  Improve the program further by modifying the `parseRssXml` function. Currently,
    this function parses the XML but limits the number of RSS structures
    to a maximum of 100. Write another function to count the number of
    items in the XML and use it to instead dynamically allocate an RSS
    array of a size exactly equal to the number of item elements in the
    XML file.
