#include "Base.hpp"

int	main()
{
	Base* b;
	Base* c;
	b = generate();
	c = generate();
	identify(b);
	identify(c);
	identify(*b);
	identify(*c);
	delete(b);
	delete(c);
	return (0);
}