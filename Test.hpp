/*
 * file:       Test.hpp
 *
 * created:    02.09.2016
 * author:     Anton Kashcheev
 */
#ifndef TEST_HPP
#define TEST_HPP

namespace tpl
{

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

//	virtual start() = 0;
private:
	void abstractFactory();
	void builder();
	void factoryMethod();
	void prototype();
	void singleton();
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
