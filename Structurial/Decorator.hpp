/*
 * file:       Decorator.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_DECORATOR_HPP
#define STRUCTURIAL_DECORATOR_HPP

template<class Object>
class Decorator
{
public:
	Decorator() {}
	Decorator(const Decorator &) {}
	Decorator(Decorator &&) {}
	~Decorator() {}

	Decorator& operator =(const Decorator &) {}
	Decorator& operator =(Decorator &&) {}
};

#endif // STRUCTURIAL_DECORATOR_HPP
