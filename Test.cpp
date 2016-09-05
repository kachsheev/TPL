/*
 * file:       Test.cpp
 *
 * created:    02.09.2016
 * author:     Anton Kashcheev
 */

#include <iostream>

#include "Test.hpp"

using namespace tpl;

// Common
void Common::start()
{
	aggregator();
	uniquePointer();
}

#include "Common/Aggregator.hpp"
void Common::aggregator()
{
	templates::Aggregator<int, long, float, double> primitiveTuple;
	std::cout << "Aggregator number: " << primitiveTuple.countArgs() << '\n'
			<< "Aggregator size: " << sizeof(primitiveTuple) << '\n';
}
#undef COMMON_AGGREGATOR_HPP

#include "Common/UniquePointer.hpp"
void Common::uniquePointer()
{
}

