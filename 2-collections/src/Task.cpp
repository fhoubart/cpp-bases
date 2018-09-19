#include "../include/Task.h"

Task::Task(string title) {
    this->_title = title;
}

string Task::getTitle() {
    return _title;
}

bool Task::isDone() {
    return _done;
}

void Task::done() {
    _done = true;
}
