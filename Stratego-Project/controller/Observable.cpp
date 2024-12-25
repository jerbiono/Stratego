#include "Observable.h"
#include "../gui/Observer.h"

void Observable::registerObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Observable::unregisterObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Observable::notifyObservers() const
{
    for (Observer * observer : observers_)
    {
        observer->update((void *)this);
    }
}
