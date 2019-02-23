#include <kipr/botball.h>
//above int main, call out ports and other items as int or integers and then later call them by name instead of numbers.  
//this is easier if you do the work to enter the settings up top here.
//if you need to change settings or port numbers, you can make a single change in this area

int arm_port=0; //name arm port
int arm_up=0;//position for arm in up position
int arm_down=1200;//position for arm in down position

int sweep_port=2; //name sweep port
int sweep_l=0; //left position for sweeper
int sweep_r=1484; //right position for sweeper 

int right_motor=0; //port for right motor
int left_motor=2; //port for left motor

int fire_tube=5000;//ticks from start to fire tube

int main()

{
    wait_for_light(2);
    shut_down_in(110);
    enable_servos();
    set_servo_position(arm_port,arm_up);//set arm up
    msleep(500);
    set_servo_position(sweep_port,sweep_r);//open claw
    msleep(1000);

    camera_open_black();

    while (analog(1) <= 2000)//if distance sensor is far away
    {
        if(get_object_center_x(0,0)<65)
        {mav(left_motor,10);
         mav(right_motor,500);//the object is on left, turn left
        }

        if (get_object_center_x(0,0)>95)
        {
            mav(left_motor,500);
            mav(right_motor,10); //the object is on right, turn right
        }
        if (get_object_center_x(0,0)>= 65 && get_object_center_x(0,0)<=95)
        {
            mav(left_motor,500);
            mav(right_motor,500);//object is in the middle, go straight
        }
    }
    msleep(2000);
    set_servo_position(arm_port,arm_down);//drop claw arm
    msleep(1000);
    set_servo_position(sweep_port,sweep_l);//sweep left
    msleep(500);




    disable_servos();
    return 0;
    ao();

}