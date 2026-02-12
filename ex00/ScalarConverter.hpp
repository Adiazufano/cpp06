#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <iomanip>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::exception;

class ScalarConverter
{
private:
	ScalarConverter();
public:
	static void convert(string param);
};
#endif
