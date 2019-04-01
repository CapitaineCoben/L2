/**
* \file gold.h
*/
#ifndef GOLD_H
#define GOLD_H
#include "metal.h" // for metal_t
/**
* A gold metal.
*/
class gold_t: public metal_t
{
public:
/**
* Constructs a new gold metal.
* Initializes its name to "Gold" and its symbol to "Au".
*/
gold_t();
};
#endif
