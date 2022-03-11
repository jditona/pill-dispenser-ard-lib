#include "HopperDisk.h"
#include "Stepper.h"
#define DEBUG Serial
#define STEPS 200
#define SPEED 30

HopperDisk::HopperDisk(uint8_t disk_pin, uint8_t disk_dir_pin)
    :_disk(STEPS, disk_pin, disk_dir_pin)
{
    this->_disk_pin = disk_pin;
    this->_disk_dir_pin = disk_dir_pin;
    this->_disk.setSpeed(SPEED);
};

void HopperDisk::rotate_disk(uint8_t steps){
    /*
     * Function that rotates disk by a given number of steps
     *  Args:
     *      steps(uint8_t)      Max step size dictated by max uint8_t (256)
     *  Returns:
     *      None
     */
    
    #include <Stepper.h>
    const int stepsPerRevolution = 200;// change to fit number of steps per revolution for motor
    #define stepperDirA 2
    #define stepperStepA 3


    int count = 0;

    void setup() {
    
    Serial.begin(9600);
    pinMode(stepperDirA, OUTPUT);
    pinMode(stepperStepA, OUTPUT);
    digitalWrite(stepperDirA,LOW); //LOW = CCW HIGH = CW

}

    void loop() {

       while (count < 950 ){    // SPIN if UNbroken
        digitalWrite(stepperStepA, HIGH);
        //digitalWrite(stepperStepB, HIGH);
        delayMicroseconds(400);
        digitalWrite(stepperStepA, LOW);
        //digitalWrite(stepperStepB, LOW);
        delayMicroseconds(400); //range of delay 500- 1200 fast motor to slow; 1350 seems alright 4000 seems okay for disk
        count++;
        }

    }

    
    this->_disk.step(steps);
    DEBUG.println("HopperDisk.cpp: Rotating disk...");
}
