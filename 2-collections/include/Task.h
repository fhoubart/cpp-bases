#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__

#include <string>

using namespace std;

/**
 * A Task represent a single task that can be done or not.
 */
class Task {

    public:
        /**
         * Create a new Task
         */
        Task(string title);

        /**
         * Get the title of the Task
         */
        string getTitle();


        /**
         * Check if the Task is done or not.
         **/
        bool isDone();

        /**
         * Mark this task as done.
         */
        void done();

    private:
        string _title;
        bool _done;
};

#endif