CC=g++
CFLAGS= -std=c++98 -pedantic -Wall -Werror -g `pkg-config pugixml --cflags`
LDFLAGS=`pkg-config pugixml --libs-only-L`
LDLIBS=`pkg-config pugixml --libs-only-l`
RM=rm -fv
all: mrp.out
refinery.o: refinery.cpp refinery.h
	$(CC) $(CFLAGS) -c -o refinery.o refinery.cpp
metal.o: metal.cpp metal.h
	$(CC) $(CFLAGS) -c -o metal.o metal.cpp
copper.o: copper.cpp copper.h
	$(CC) $(CFLAGS) -c -o copper.o copper.cpp
silver.o: silver.cpp silver.h
	$(CC) $(CFLAGS) -c -o silver.o silver.cpp
gold.o: gold.cpp gold.h
	$(CC) $(CFLAGS) -c -o gold.o gold.cpp
mrp.out: mrp.cpp refinery.o metal.o copper.o gold.o silver.o
	$(CC) $(CFLAGS) -o mrp.out mrp.cpp refinery.o metal.o copper.o gold.o silver.o $(LDFLAGS) $(LDLIBS)
clean:
	$(RM)	*.o	*.out
