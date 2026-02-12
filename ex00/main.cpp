#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Error: need two params" << endl;
		return (1);
	}
	string p = "\t";
	ScalarConverter::convert(argv[1]);
	return (0);
}