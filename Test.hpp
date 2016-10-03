/*
 * file:       Test.hpp
 *
 * created:    02.09.2016
 * author:     Anton Kashcheev
 */
#ifndef TEST_HPP
#define TEST_HPP

#include <stdint.h>
#include <cassert>

namespace tpl
{

template<typename Type>
class Object
{
public:
	Object() = delete;
	Object(const Object &) = delete;
	Object(Object &&) = delete;
	Object(unsigned int arraySize) :
			arrSize(arraySize)
	{
		assert(arraySize != 0);
		array = new Type[arrSize];
	}

	~Object()
	{
		delete[] array;
	}

	Type &operator [](unsigned int index)
	{
		return array[index];
	}

	unsigned int size()
	{
		return arrSize;
	}

private:
	Type *array;
	unsigned int arrSize;
};

class Test
{
public:
	Test()
	{
	}

	virtual ~Test()
	{
	}

	virtual void start() = 0;
};

class Common: public Test
{
public:
	Common()
	{
	}

	virtual ~Common()
	{
	}

	virtual void start();
private:
	void aggregator();
	void uniquePointer();
};

class CreationalPatterns: public Test
{
public:
	CreationalPatterns()
	{
	}

	virtual ~CreationalPatterns()
	{
	}

	virtual void start();
private:
	void abstractFactory();
	void builder();
	void factoryMethod();
	void prototype();
	void singleton();
	void objectPool();
};

class StructurialPatterns: public Test
{
public:
	StructurialPatterns()
	{
	}

	virtual ~StructurialPatterns();

//	virtual start() = 0;
private:
};

}

#endif // TEST_HPP
