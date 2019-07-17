#include "mbed.h"
#include "stepper.hpp"
#include "motor_wrapper.hpp"
#include "F746_GUI.hpp"
#include "mtmotor.hpp"

PwmOut IN1(PB_14);
PwmOut IN2(PF_6);

int main()
{//tuyo
    Stepper alpha_rotation(PA_15,PI_2);
    alpha_rotation.set_accel(2500);
    alpha_rotation.set_rpm(1000);
    //mtmotor mtest(PI_1,PF_6);
    
    Button up(20,20,120,50,"Monter");
    Button down(160,20,120,50,"Descendre");
    Button Pince( 320, 20, 150 , 50, "Actionner Pince");
    Button forward(20, 80, 120, 50, "Avancer");
    Button backward(160, 80, 120, 50, "Reculer");
    
    Button rotate_left(20, 220, 60, 30, "Gauche");
    Button rotate_right(90, 220, 60, 30, "Droite");
    
    SeekBar indicator (180, 230, 200, 0, 230, 0);
    
    Label motor_chariot_status(20, 140, "Moteur chariot : En pause");
    Label motor_enrouleur_status(20, 160, "Moteur enrouleur : En pause");
    
    int angle(0);
    bool touched(false);
    bool touched_1(false);
    bool redraw_1(false);
    bool touched_2(false);
    bool redraw_2(false);
    
    while(1)
    {
        if(rotate_left.Touched() && !(touched))
        {
         rotate_right.Draw();
         angle-=10;
         if(angle<0)angle=230;
         indicator.Draw(angle);
         alpha_rotation.move(-10);
         touched=true;
        }
        else if (rotate_right.Touched() && !touched)
        {
         rotate_left.Draw();
         angle+=10;
         if(angle>230)angle=0;
         indicator.Draw(angle);
         alpha_rotation.move(10);  
         touched=true;
        }
        else if(!rotate_right.Touched() && !rotate_left.Touched())
        {
         touched=false;   
        }   
        
        
        if(up.Touched() && !(touched_1))
        {
         up.Draw();
         motor_enrouleur_status.Draw("Moteur enrouleur : Avant");
         // motor_wrapper ...
         touched_1=true;
         redraw_1=true;
        }
        else if (down.Touched() && !touched_1)
        {
         down.Draw();
         motor_enrouleur_status.Draw("Moteur enrouleur : Arriere");
         //motor_wrapper ...
         touched_1=true;
         redraw_1=true;
        }
        else if(!up.Touched() && !down.Touched())
        {
         if(redraw_1)
         {
            motor_enrouleur_status.Draw("Moteur enrouleur : En pause");
            redraw_1=false;
        }
         touched_1=false;   
        }
        
        if(forward.Touched() && !(touched_2))
        {
         forward.Draw();
         motor_enrouleur_status.Draw("Moteur enrouleur : Avant");
            motor_chariot_status.Draw("Moteur chariot : Avant");
         // motor_wrapper ...
         IN1.write(1);
                IN2.write(0.5);
         touched_2=true;
         redraw_2=true;
        }
        else if (backward.Touched() && !touched_2)
        {
         backward.Draw();
         motor_enrouleur_status.Draw("Moteur enrouleur : Arriere");
            motor_chariot_status.Draw("Moteur chariot : Arriere");
            IN1.write(0.5);
                IN2.write(1);
         //motor_wrapper ...
         touched_2=true;
         redraw_2=true;
        }
        else if(!forward.Touched() && !backward.Touched())
        {
         if(redraw_2)
         {
            motor_enrouleur_status.Draw("Moteur enrouleur : En pause");
            motor_chariot_status.Draw("Moteur chariot : En pause");
            IN1.write(0);
            IN2.write(0);
            redraw_2=false;
        }
         touched_2=false;   
        }
        //indicator.SetValue(angle);
        
        
        wait_us(200);
    }
    return 0;   
}