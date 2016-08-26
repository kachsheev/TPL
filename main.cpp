/*
 * file:       main.cpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

//#include <iostream>

#include "Creational/AbstractFactory.hpp"
#include "Creational/Prototype.hpp"
//#include "Creational/Builder.hpp"

tplAbstractFactory(LolFactory, "Factory LolFactory created")
tplPrototype(LolPrototype, "Prototype LolPrototype created")

int main(int /*argc*/, char **/*argv*/)
{
	tpl::LolFactory lolFactory;
	tpl::LolPrototype lolPrototype;
//	std::cout << "Hello World!\n";
	return 0;
}
