/*
 * file:       Test.cpp
 *
 * created:    02.09.2016
 * author:     Anton Kashcheev
 */

#include <cassert>
#include <iostream>

#include "Common/UniquePointer.hpp"
#include "Common/Aggregator.hpp"

#include "Creational/FactoryMethod.hpp"
#include "Creational/AbstractFactory.hpp"
#include "Creational/Builder.hpp"
#include "Creational/Prototype.hpp"
#include "Creational/Singleton.hpp"
#include "Creational/ObjectPool.hpp"

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
	std::cout << "Object<long>:";
	templates::UniquePointer<Object<long>> uniquePointer = templates::makeUnique<Object<long>>(size_t(4));
	Object<long> &object = *uniquePointer;
	for (size_t i = 0; i < object.size(); ++i)
	{
		object[i] = (i + 1) * (i + 1);
		std::cout << ' ' << object[i];
	}
	std::cout << '\n';

	std::cout << "Object<long> (moved):";
	templates::UniquePointer<Object<long>> uniquePointer2 = uniquePointer;
	for (size_t i = 0; i < object.size(); ++i)
	{
		object[i] = (i + 1) * (i + 1);
		std::cout << ' ' << uniquePointer2.operator *()[i];
	}
	std::cout << '\n';
}
