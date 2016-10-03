/*
 * file:       Builder.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef CREATIONAL_BUILDER_HPP
#define CREATIONAL_BUILDER_HPP

#include <cstdint>

#include "../Common/Templates.hpp"
#include "../Common/Aggregator.hpp"

// declaration
namespace tpl
{

// default
template<class ObjectPart>
class Builder
{
public:
	~Builder()
	{
	}

	template<class ... Args>
	ObjectPart getPart(Args &&... args); // specialize for each type
};

// reference
template<class ObjectPart>
class Builder<ObjectPart &>
{
public:
	~Builder()
	{
	}

	template<class ... Args>
	ObjectPart &getPart(Args &&... args); // specialize for each type
};

// const reference
template<class ObjectPart>
class Builder<const ObjectPart &>
{
public:
	~Builder()
	{
	}

	template<class ... Args>
	ObjectPart &getPart(Args &&... args); // specialize for each type
};

// pointer
template<class ObjectPart>
class Builder<ObjectPart *>
{
public:
	~Builder()
	{
	}

	template<class ... Args>
	ObjectPart *getPart(Args &&... args); // specialize for each type
};

// pointer
template<class ObjectPart>
class Builder<const ObjectPart *>
{
public:
	~Builder()
	{
	}

	template<class ... Args>
	const ObjectPart *getPart(Args &&... args); // specialize for each type
};

template<class Object, class ... ObjectParts>
class Director
{
	const std::size_t countArgs = templates::countArgs<ObjectParts ...>();
	templates::Aggregator<Builder<ObjectParts> ...> aggregator;
public:
	Director();
	~Director();

	template<class ... Args>
	Object *getInstance(Args &&... args); // specialize for each type
};

}

// implementation
namespace tpl
{

template<class Object, class ... ObjectParts>
Director<Object, ObjectParts ...>::Director()
{
}

}

#endif // CREATIONAL_BUILDER_HPP
