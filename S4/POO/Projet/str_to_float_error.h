/**
* \file str_to_float_error.h
*/
#ifndef STR_TO_FLOAT_ERROR_H
#define STR_TO_FLOAT_ERROR_H
#include <exception> // for exception
#include <string> // for string
using namespace std; // for string
/**
* A string to float conversion exception.
*/
class str_to_float_error: public exception
{
string str; /**< The string describing this string to float conversion exception. */
public:
/**
* Constructs a new string to float conversion exception.
* \param str The string that cannot be converted to a float.
*/
str_to_float_error(string str);
/**
* Destroys an existing string to float conversion exception.
*/
~str_to_float_error() throw ();
/**
* Creates a string describing this string to float conversion exception.
* This string is "CN: unable to convert the string \"SV\" to a float".
* CN: The name of this class.
* SV: The str attribute value.
* \returns The string describing this string to float conversion exception.
*/
const char *what() const throw ();
};
#endif
