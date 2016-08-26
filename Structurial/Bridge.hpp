/*
 * file:       Bridge.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_BRIDGE_HPP
#define STRUCTURIAL_BRIDGE_HPP

template<class Object>
class Bridge
{
public:
	Bridge() {}
	Bridge(const Bridge &) {}
	Bridge(Bridge &&) {}
	~Bridge() {}

	Bridge& operator =(const Bridge &) {}
	Bridge& operator =(Bridge &&) {}
};

#endif // STRUCTURIAL_BRIDGE_HPP
