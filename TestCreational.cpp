#include <cassert>
#include <iostream>

#include "Creational/FactoryMethod.hpp"
#include "Creational/AbstractFactory.hpp"
#include "Creational/Builder.hpp"
#include "Creational/Prototype.hpp"
#include "Creational/Singleton.hpp"
#include "Creational/ObjectPool.hpp"

#include "Test.hpp"

using namespace	tpl;

// CreationalPatterns
void CreationalPatterns::start()
{
	abstractFactory();
	builder();
	factoryMethod();
	prototype();
	singleton();
	objectPool();
}

typedef Object<long> TestObject;
tplAbstractFactory(TestFactory, TestObject)

void CreationalPatterns::abstractFactory()
{
}

void CreationalPatterns::builder()
{

}

void CreationalPatterns::factoryMethod()
{

}

void CreationalPatterns::prototype()
{

}

void CreationalPatterns::singleton()
{

}

void CreationalPatterns::objectPool()
{

}
