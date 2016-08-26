/*
 * file:       Flyweight.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_FLYWEIGHT_HPP
#define STRUCTURIAL_FLYWEIGHT_HPP

template<class Object>
class Flyweight
{
public:
	Flyweight() {}
	Flyweight(const Flyweight &) {}
	Flyweight(Flyweight &&) {}
	~Flyweight() {}

	Flyweight& operator =(const Flyweight &) {}
	Flyweight& operator =(Flyweight &&) {}
};

#endif // STRUCTURIAL_FLYWEIGHT_HPP
