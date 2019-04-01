/**
* \file silver.h
*/
#ifndef SILVER_H
#define SILVER_H
#include "metal.h" // for metal_t
/**
* A silver metal.
*/
class silver_t: public metal_t
{
public:
/**
* Constructs a new silver metal.
* Initializes its name to "Silver" and its symbol to "Ag".
*/
silver_t();
};
#endif
