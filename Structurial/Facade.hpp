/*
 * file:       Facade.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_FACADE_HPP
#define STRUCTURIAL_FACADE_HPP

template<class Object>
class Facade
{
public:
	Facade() {}
	Facade(const Facade &) {}
	Facade(Facade &&) {}
	~Facade() {}

	Facade& operator =(const Facade &) {}
	Facade& operator =(Facade &&) {}
};

#endif // STRUCTURIAL_FACADE_HPP
