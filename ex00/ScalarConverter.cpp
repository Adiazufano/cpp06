#include "ScalarConverter.hpp"

static bool	isChar(string param)
{
	if (param.length() > 1 || isdigit(param[0]))
		return(false);
	return(true);
}

static bool	isInt(string param)
{
	char *end;//puntero que apunta al final de la cadena
	long value = std::strtol(param.c_str(), &end, 10);
	if (*end != '\0')
		return (false);
	(void)value;
	return (true);
}

static bool	isDouble(string param)
{
	char *end;//puntero que apunta al final de la cadena
	std::strtod(param.c_str(), &end);
	return (*end == '\0' && param.find('.') != string::npos);
}

static bool	isFloat(string param)
{
	char *end;//puntero que apunta al final de la cadena
	std::strtod(param.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool	isSpecial(string param)
{
	return (param == "nan" || param == "nanf" ||
			param == "inf" || param == "inff" ||
			param == "+inf" || param == "+inff" ||
			param == "-inf" || param == "-inff");
}

static void convertFromChar(string param)
{
	int charToInt = static_cast<int>(param[0]);
	double charToDouble = static_cast<double>(param[0]);
	float charToFloat = static_cast<float>(param[0]);

	if (!isprint(param[0]))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << param[0] << endl;
	cout << "int: " << charToInt << endl;
	cout << "float: " << std::fixed << std::setprecision(1) << charToFloat << 'f' << endl;
	cout << "double: " << std::fixed << std::setprecision(1) << charToDouble << endl;
}

static void convertFromInt(string param)
{
	char *end;
	long value = std::strtol(param.c_str(), &end, 10);
	char intToChar = static_cast<char>(value);
	double intToDouble = static_cast<double>(value);
	float intToFloat = static_cast<float>(value);

	if (!isprint(intToChar))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << intToChar << endl;
	if (value > INT_MAX || value < INT_MIN)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << value << endl;
	cout << "float: " << std::fixed << std::setprecision(1) << intToFloat << 'f' << endl;
	cout << "double: " << std::fixed << std::setprecision(1) << intToDouble << endl;
}

static void convertFromFloat(string param)
{
	char *end;
	float value = std::strtod(param.c_str(), &end);
	char floatToChar = static_cast<char>(value);
	double floatToInt = static_cast<int>(value);
	float floatToDouble = static_cast<double>(value);

	if (!isprint(floatToChar))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << floatToChar << endl;
	cout << "int: " << floatToInt << endl;
	cout << "float: " << std::fixed << std::setprecision(1) << value << 'f' << endl;
	cout << "double: " << std::fixed << std::setprecision(1) << floatToDouble << endl;
}

static void convertFromDouble(string param)
{
	char *end;
	double value = std::strtod(param.c_str(), &end);
	char doubleToChar = static_cast<char>(value);
	double doubleToInt = static_cast<int>(value);
	float doubleToFloat = static_cast<float>(value);

	if (!isprint(doubleToChar))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << doubleToChar << endl;
	cout << "int: " << doubleToInt << endl;
	cout << "float: " << std::fixed << std::setprecision(1) << doubleToFloat << 'f' << endl;
	cout << "double: " << std::fixed << std::setprecision(1) << value << endl;
}

static void	printSpecial(string param)
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;

	if (param == "nanf" || param == "inff" || param == "+inff" || param == "-inff")
	{	std::cout << "float: " << param << std::endl;
		// Quitamos la 'f' del final para el double
		std::cout << "double: " << param.substr(0, param.length() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << param << "f" << std::endl;
		std::cout << "double: " << param << std::endl;
	}
}

void	ScalarConverter::convert(string param)
{
	if (isSpecial(param))
	{
		printSpecial(param);
		return;
	}
	if (isChar(param))
		convertFromChar(param);
	else if (isInt(param))      // Primero el Int, porque strtod también leería un Int
		convertFromInt(param);
	else if (isFloat(param))    // Luego el Float (busca la 'f')
		convertFromFloat(param);
	else if (isDouble(param))   // Luego el Double (si tiene punto y no 'f')
		convertFromDouble(param);
}