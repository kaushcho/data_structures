#include "checkrelB.hpp"
#include "checkrelA.hpp"
Beta::Beta() {
		y=0;
}

void Beta::printB() {
		cout<<"printB called from printA"<<endl;
	    	y=a.x;
		cout<<"The value of y is now: "<<y<<endl;
}

