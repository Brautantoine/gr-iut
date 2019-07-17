#ifndef MOTOR_WRAPPER_HPP
#define MOTOR_WRAPPER_HPP

#include "mtmotor.hpp"
//#include "sigKillMotor.hpp"

class motor_wrapper
{
  public :
    enum MOTOR_CHOICE{CHARIOT,GRABBER};
    motor_wrapper(mtmotor _chariot,mtmotor _grabber);
    virtual ~motor_wrapper();

    void forward(MOTOR_CHOICE motor_choice);
    void backward(MOTOR_CHOICE motor_choice);
    //void stop(sigKillMotor signal);

    

  private :

    mtmotor chariot;
    mtmotor grabber;

};

#endif // MOTOR_WRAPPER_HPP