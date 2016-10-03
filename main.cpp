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
	tpl::Test *structurial = nullptr; //new tpl::StructurialPatterns();
	tpl::Test *creational = nullptr; //new tpl::CreationalPatterns();

	common->start();
	structurial->start();
//	creational->start();

	delete common;
	delete structurial;
	delete creational;

	return 0;
}
