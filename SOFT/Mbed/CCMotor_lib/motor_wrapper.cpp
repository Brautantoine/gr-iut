#include "motor_wrapper.hpp"


motor_wrapper::motor_wrapper(mtmotor _chariot,mtmotor _grabber) : chariot(_chariot) , grabber(_grabber)
{

}

motor_wrapper::~motor_wrapper()
{

}

void motor_wrapper::forward(MOTOR_CHOICE motor_choice)
{
  if(motor_choice==CHARIOT)
    chariot.move(mtmotor::forward);
  grabber.move(mtmotor::forward);
}

void motor_wrapper::backward(MOTOR_CHOICE motor_choice)
{
  if(motor_choice==CHARIOT)
    chariot.move(mtmotor::backward);
  grabber.move(mtmotor::backward);
}

/*void motor_wrapper::stop(sigKillMotor signal)
{

}*/