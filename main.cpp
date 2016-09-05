/*
 * file:       main.cpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

//#include <iostream>

//#include "Creational/AbstractFactory.hpp"
//#include "Creational/Prototype.hpp"
//#include "Creational/Builder.hpp"

#include "Test.hpp"

int main(int /*argc*/, char **/*argv*/)
{
	tpl::Test *common = new tpl::Common;
//	tpl::Test *structurial = new tpl::StructurialPatterns();
//	tpl::Test *creational = new tpl::CreationalPatterns();

	common->start();

	return 0;
}
