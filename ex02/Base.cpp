#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <sys/time.h>


Base::~Base()
{
}

Base*	generate(void)
{
	struct timeval	tv;
	gettimeofday(&tv, 0);

	unsigned int	seed = tv.tv_sec ^ tv.tv_usec;
	srand(seed);
	int n = rand() % 3;
	Base* b;
	switch (n)
	{
		case 0:
			b = new A();
			break;
		case 1:
			b = new B();
			break;
		default:
			b = new C();
	}
	return (b);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "Pointer type: A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "Pointer type: B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "Pointer type: C" << endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		cout << "Reference type: A" << endl;
		(void)a;
		return;
	}
	catch(std::exception &bc)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		cout << "Reference type: B" << endl;
		(void)b;
		return;
	}
	catch(std::exception &bc)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		cout << "Reference type: C" << endl;
		(void)c;
		return;
	}
	catch(std::exception &bc)
	{
	}
}