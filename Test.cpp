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

	primitiveTuple.initialize<0u>(-10);
	primitiveTuple.initialize<1u>(100000l);
	primitiveTuple.initialize<2u>(-10.01f);
	primitiveTuple.initialize<3u>(1001.25);

	std::cout << primitiveTuple.get<0u>() << ' '
			<< primitiveTuple.get<1u>() << ' '
			<< primitiveTuple.get<2u>() << ' '
			<< primitiveTuple.get<3u>() << '\n';

	std::cout << *primitiveTuple.pointer<0u>() << ' '
			  << *primitiveTuple.pointer<1u>() << ' '
			  << *primitiveTuple.pointer<2u>() << ' '
			  << *primitiveTuple.pointer<3u>() << '\n';
}

void Common::uniquePointer()
{
}

