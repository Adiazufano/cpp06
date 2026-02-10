#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Error: need two params" << endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}