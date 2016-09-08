/*
 * file:       Test.cpp
 *
 * created:    02.09.2016
 * author:     Anton Kashcheev
 */

#include <iostream>

#include "Common/UniquePointer.hpp"
#include "Common/Aggregator.hpp"
#include "Test.hpp"

using namespace tpl;

// Common
void Common::start()
{
	aggregator();
	uniquePointer();
}

void Common::aggregator()
{
	templates::Aggregator<int, long, float, double> primitiveTuple;
	std::cout << "Aggregator number: " << primitiveTuple.countArgs() << '\n'
			<< "Aggregator size: " << sizeof(primitiveTuple) << '\n';

	primitiveTuple.initialize<0>(-10);
}

void Common::uniquePointer()
{
}
