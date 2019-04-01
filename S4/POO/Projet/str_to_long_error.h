/**
* \file str_to_long_error.h
*/
#ifndef STR_TO_LONG_ERROR_H
#define STR_TO_LONG_ERROR_H
#include <exception> // for exception
#include <string> // for string
using namespace std; // for string
/**
* A string to long conversion exception.
*/
class str_to_long_error: public exception
{
string str; /**< The string describing this string to long conversion exception. */
public:
/**
* Constructs a new string to long conversion exception.
* \param str The string that cannot be converted to a long.
*/
str_to_long_error(string str);
/**
* Destroys an existing string to long conversion exception.
*/
~str_to_long_error() throw ();
/**
* Creates a string describing this string to long conversion exception.
* This string is "CN: unable to convert the string \"SV\" to a long".
* CN: The name of this class.
* SV: The str attribute value.
* \returns The string describing this string to long conversion exception.
*/
const char *what() const throw ();
};
#endif
