/*
 * file:       Composite.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_COMPOSITE_HPP
#define STRUCTURIAL_COMPOSITE_HPP

template<class Object>
class Composite
{
public:
	Composite() {}
	Composite(const Composite &) {}
	Composite(Composite &&) {}
	~Composite() {}

	Composite& operator =(const Composite &) {}
	Composite& operator =(Composite &&) {}
};

#endif // STRUCTURIAL_COMPOSITE_HPP
