#include <ARRAY.h>
#include <MOTORS.h>

MOTORS motors(11, 8, 9, 12, 13, 10);
ARRAY array(A0, A1, A2, A3, A4);

// Global constants for sensor values
const unsigned int black = 0;
const unsigned int white = 1;

// Global constant for turning speed
const unsigned int complete_turn_speed = 85;
const unsigned int slight_turn_speed = 75;
const unsigned int low_turn_speed = 65;
const unsigned int forward_speed = 75;
const unsigned int uTurn_speed = 65;

// Function to check if a sensor is on black
bool isBlack(int sensor) { return (sensor == white); }

void setup()
{
  Serial.begin(9600);

  pinMode(A0, INPUT); // Extreme left sensor
  pinMode(A1, INPUT); // Left sensor
  pinMode(A2, INPUT); // Middle sensor
  pinMode(A3, INPUT); // Right sensor
  pinMode(A4, INPUT); // Extreme right sensor
}

void loop()
{
  // Read sensor values
  int sensor5 = digitalRead(A0); // Extreme left sensor
  int sensor4 = digitalRead(A1); // Left sensor
  int sensor3 = digitalRead(A2); // Middle sensor
  int sensor2 = digitalRead(A3); // Right sensor
  int sensor1 = digitalRead(A4); // Extreme right sensor

  if (isBlack(sensor1))
  {
    if (isBlack(sensor2))
    {
      if (isBlack(sensor3))
      {
        if (isBlack(sensor4))
        {
          if (isBlack(sensor5))
          {
            // ⚫⚫⚫⚫⚫
            motors.stop();
          }
          else
          {
            // ⚪⚫⚫⚫⚫
            motors.turnRight(slight_turn_speed);
          }
        }
        else
        {
          // ⚪⚪⚫⚫⚫
          motors.turnRight(complete_turn_speed);
        }
      }
      else
      {
        // ⚪⚪⚪⚫⚫
        motors.turnRight(slight_turn_speed);
      }
    }
    else
    {
      // ⚪⚪⚪⚪⚫
      motors.turnRight(complete_turn_speed);
    }
  }
  else if (isBlack(sensor2))
  {
    if (isBlack(sensor3))
    {
      if (isBlack(sensor4))
      {
        if (isBlack(sensor5))
        {
          // ⚫⚫⚫⚫⚪
          motors.turnLeft(slight_turn_speed);
        }
        else
        {
          // ⚪⚫⚫⚫⚪
          motors.forward(forward_speed);
        }
      }
      else
      {
        // ⚪⚪⚫⚫⚪
        motors.turnRight(low_turn_speed);
      }
    }
    else
    {
      // ⚪⚪⚪⚫⚪
      motors.turnRight(slight_turn_speed);
    }
  }
  else if (isBlack(sensor3))
  {
    if (isBlack(sensor4))
    {
      if (isBlack(sensor5))
      {
        // ⚫⚫⚫⚪⚪
        motors.turnLeft(complete_turn_speed);
      }
      else
      {
        // ⚪⚫⚫⚪⚪
        motors.turnLeft(low_turn_speed);
      }
    }
    else
    {
      // ⚪⚪⚫⚪⚪
      motors.forward(forward_speed);
    }
  }
  else if (isBlack(sensor4))
  {
    if (isBlack(sensor5))
    {
      // ⚫⚫⚪⚪⚪
      motors.turnLeft(complete_turn_speed);
    }
    else
    {
      // ⚪⚫⚪⚪⚪
      motors.turnLeft(low_turn_speed);
    }
  }
  else if (isBlack(sensor5))
  {
    // ⚫⚪⚪⚪⚪
    motors.turnLeft(complete_turn_speed);
  }
  else
  {
    // ⚪⚪⚪⚪⚪
    motors.turnLeft(uTurn_speed, uTurn_speed); // turning around
  }
}