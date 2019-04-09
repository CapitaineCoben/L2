/**
* \file copper.h
*/
#ifndef COPPER_H
#define COPPER_H
#include "metal.h" // for metal_t
/**
* A copper metal.
*/
class copper_t: public metal_t{
public:
/**
* Constructs a new copper metal.
* Initializes its name to "Copper" and its symbol to "Cu".
*/
copper_t();
};
#endif
