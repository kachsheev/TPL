/*
 * file:       Proxy.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_PROXY_HPP
#define STRUCTURIAL_PROXY_HPP

template<class Object>
class Proxy
{
public:
	Proxy() {}
	Proxy(const Proxy &) {}
	Proxy(Proxy &&) {}
	~Proxy() {}

	Proxy& operator =(const Proxy &) {}
	Proxy& operator =(Proxy &&) {}
};

#endif // STRUCTURIAL_PROXY_HPP
