/*
 * file:       Builder.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef CREATIONAL_BUILDER_HPP
#define CREATIONAL_BUILDER_HPP

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
	Aggregator<ObjectParts ...> aggregator;
public:
	Director();
	~Director();

	Object *getInstance();
};

#endif // CREATIONAL_BUILDER_HPP
