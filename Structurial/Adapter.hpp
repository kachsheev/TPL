/*
 * file:       Adapter.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_ADAPTER_HPP
#define STRUCTURIAL_ADAPTER_HPP

template<class Object>
class Adapter
{
    Object object;
public:
    Adapter();

    template<class ... Args>
    Adapter(Args ... args);
};

#endif // STRUCTURIAL_ADAPTER_HPP
