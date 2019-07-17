#include "mtmotor.hpp"

mtmotor::mtmotor(PwmOut _IN1, PwmOut _IN2): IN1(_IN1), IN2(_IN2)
{
    endFront = false;   
    endBack = false;
    
    event = false;
    
    motorDir = forward;
    running = false;
    
    motorTask.start(callback(this,&mtmotor::_motorTask));
}
  
mtmotor::~mtmotor()
{
  
}
  
void mtmotor::move(motorDirection dir)
{
 event_mutex.lock();
 
 if(dir == forward)
 {
  running = true;
  motorDir = forward;
  event = true;
 }
 else
 {
  running = true;
  motorDir = backward;
  event = true;
 }
  event_mutex.unlock();      
}
  
void mtmotor::stop()
{
 running = false;
 event = false;   
}

void mtmotor::_motorTask()
{
    while(1)
    {
     if(event)
     {
      event_mutex.lock();
      
      if(running)
      {
            if(motorDir == forward && !endFront)
            {
                IN1.write(1);
                IN2.write(0.5);
                endBack=false;
            }
            else if(motorDir == backward && !endBack)
            {
                IN1.write(0.5);
                IN2.write(1);
                endFront=false;
            }
      }
      else
      {
            IN1.write(0);
            IN2.write(0);   
      }
      
      event = false;   
      event_mutex.unlock();
     }
     Thread::wait(200);
       
    }
       
}