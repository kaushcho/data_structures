#include "checkrelA.hpp"
#include "checkrelB.hpp"

Alpha::Alpha() {
		b = new Beta();
		x=0;
}
Alpha::~Alpha() {
		delete b;
}
Alpha a;
int main()
{
		
	//	a.setX();
	//	a.b->printB();
		return 0;
}

