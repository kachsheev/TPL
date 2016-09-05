/*
 * file:       Builder.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef CREATIONAL_BUILDER_HPP
#define CREATIONAL_BUILDER_HPP

#include <cstdint>

#include "../Common/Aggregator.hpp"

// declaration
namespace tpl
{

template<class ObjectPart>
class Builder
{
public:
	virtual ~Builder()
	{
	}

	ObjectPart *getPart();
};

template<class Object, class ... ObjectParts>
class Director
{
	const std::size_t countArgs = templates::getCountArguments();
	templates::Aggregator<Builder<ObjectParts> ...> aggregator;
public:
	Director();
	~Director();

	Object *getInstance();
};

}

// implementation
namespace tpl
{

template<class Object, class ... ObjectParts>
Director::Director()
{
}

}

#endif // CREATIONAL_BUILDER_HPP
