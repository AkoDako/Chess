#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>


class Observer;

class Subject {
  std::vector<Observer *> observers;
 public:
  void attach(Observer *o);
  void notifyObservers();
  void detach(Observer *o);
};


void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::detach(Observer *o) {
  observers.erase(std::remove(observers.begin(), observers.end(), o));
}

#endif
