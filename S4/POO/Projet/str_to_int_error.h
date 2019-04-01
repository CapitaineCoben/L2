/**
* \file str_to_int_error.h
*/
#ifndef STR_TO_INT_ERROR_H
#define STR_TO_INT_ERROR_H
#include <exception> // for exception
#include <string> // for string
using namespace std; // for string
/**
* A string to int conversion exception.
*/
class str_to_int_error: public exception
{
string str; /**< The string describing this string to int conversion exception. */
public:
/**
* Constructs a new string to int conversion exception.
* \param str The string that cannot be converted to an int.
*/
str_to_int_error(string str);
/**
* Destroys an existing string to int conversion exception.
*/
~str_to_int_error() throw ();
/**
* Creates a string describing this string to int conversion exception.
* This string is "CN: unable to convert the string \"SV\" to an int".
* CN: The name of this class.
* SV: The str attribute value.
* \returns The string describing this string to int conversion exception.
*/
const char *what() const throw ();
};
#endif
