#ifndef PROTOTHREADING_H
#define PROTOTHREADING_H

#include "Arduino.h"
/*
+==============================================+
|This file is the original work of Joseph Raub |
| For use with the EPL MakerSpace  2017        |
+==============================================+
*/
class Thread
{
    private:
        typedef void (*func)(void);
        func _function;
        void action();
        void update_msec();
        void fire();
        unsigned long last_msec;
        unsigned long current_msec;
        unsigned long time;
    public:
        void setCycleSpeed(int input);
        void cycle();
        void setFunc(func funct);
};

#endif // PROTOTHREADING_H
