#ifndef MTMOTOR_HPP
#define MTMOTOR_HPP

#include "mbed.h"
#include "rtos.h"

static Thread motorTask;  

class mtmotor
{
  public:
    enum motorDirection{forward,backward};
    mtmotor(PwmOut _IN1, PwmOut _IN2);  
    virtual ~mtmotor();
  
    void move(motorDirection dir);  
    void stop();
    
    

  private:
  
    void _motorTask();
  
    PwmOut IN1;
    PwmOut IN2;
    bool endFront;
    bool endBack;
    
    bool event;
    
    
    
    motorDirection motorDir;
    bool running;
    
    
    Mutex event_mutex;
};
#endif //MTMOTOR_HPP