#ifndef __TASKLIST_H_INCLUDED__
#define __TASKLIST_H_INCLUDED__

#include <vector>
#include "Task.h"

/**
 * A TaskList is a ordered list of Task object.
 * It encapsulate a vector and provide function to manage the list from stdin
 */
class TaskList {

    private:
        vector<Task*> list;
        int getItemIndexFromStdin();

    public:
        /**
         * Constructor, create an empty TaskList
         */
        TaskList();

        /**
         * Print to stdout the list of all tasks
         */
        void printTasks();

        /**
         * Ask the user to provide a title from stdin, create a Task and add it to the list
         */
        void addFromStdin();

        /**
         * Ask the user to provide the index of the task from stdin in the list and delete it.
         */
        void deleteFromStdin();

        /**
         * Ask the user to provide the index of the task from stdin and mark it as done.
         */
        void doneFromStdin();

};

#endif
