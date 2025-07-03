#
# makefile for this lab
#

# compile with gcc
CC = gcc -std=gnu99 -Wall -g -lm

# cURL library
CURL_LIB = -lcurl

# json-c
JSON_INCLUDE = -I/usr/include/json-c/
JSON_LIB = -ljson-c

run: earthquakeReport.c earthquake.o curl_utils.o
	$(CC) $(JSON_INCLUDE) -o run earthquakeReport.c curl_utils.o earthquake.o $(CURL_LIB) $(JSON_LIB) -lm

earthquake.o: earthquake.c earthquake.h
	$(CC) $(JSON_INCLUDE) -c -o earthquake.o earthquake.c $(JSON_LIB)

curl_utils.o: utils/curl_utils.c utils/curl_utils.h
	$(CC) -c -o curl_utils.o utils/curl_utils.c

curlTest: curl_utils.o
	$(CC) -o curlTest curl_utils.o tests/curlTest.c $(CURL_LIB)

jsonTest: curl_utils.o
	$(CC) $(JSON_INCLUDE) -o jsonTest curl_utils.o tests/jsonTest.c $(CURL_LIB) $(JSON_LIB)

clean:
	rm -f *.o *~
