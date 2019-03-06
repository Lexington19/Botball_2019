#include <kipr/botball.h>
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
    mav(left_motor,1000);
    mav(right_motor,1000);
    msleep(6000);//run out of starting box
    
    
    mav(left_motor,-250);//turn towards city
    msleep(1800);
    
    mav(left_motor,-500);//drive up to first pom poms
    mav(right_motor,-500);
    msleep(6500);
    
    mav(right_motor,-500);
    mav(left_motor,-20);
    msleep(1500);
    
    mav(right_motor,-700);
    mav(left_motor,-700);
    msleep(16000);//straight away
    
    mav(right_motor,0);
    mav(left_motor,700);
    msleep(3000);//reverse turn towards starting box
    
    
    mav(left_motor,-500);
    mav(right_motor,-500);
    msleep(7000);//drive before turn to box
    
    mav(left_motor,0);
    mav(right_motor,0);
    msleep(30000);//ezras robot begins
    
    mav(right_motor,0);
    mav(left_motor,700);
    msleep(3000); 
    
    mav(right_motor,0);
    mav(left_motor,-700);
    msleep(1600);
    
    
    
    
    
    
    printf("Hello World\n");
    return 0;
}
