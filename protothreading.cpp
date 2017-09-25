#include "protothreading.h"
#include "Arduino.h"
/*
+==============================================+
|This file is the original work of Joseph Raub |
| For use with the EPL MakerSpace  2017        |
+==============================================+
*/
void Thread::fire(){
    if((current_msec - last_msec) >= time){
        last_msec = current_msec;
        current_msec = 0;
        this->action();
    }
    else{}
}

void Thread::action(){
    (*_function)();
}

void Thread::setCycleSpeed(int input){
    this->time = input;
}

void Thread::update_msec(){
    this->current_msec = millis();
}

void Thread::cycle(){
    this->update_msec();
    this->fire();
}

void Thread::setFunc(func funct){
    _function = funct;
}

