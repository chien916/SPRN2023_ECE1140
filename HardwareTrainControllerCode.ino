#include <ezButton.h>

// Create ezButton objects for different buttons

// For the Train Driver

ezButton setSetpoint(7); // create eZButton object that attaches to pin 7, for setting the setpoint

ezButton buttonDoors(6); // button for opening and closing doors

ezButton buttonLights(5); // button for turning on and off the interior and exterior lights

ezButton incrSetpoint(4); // button for increasing the setpoint speed

ezButton decrSetpoint(3); // button for decreasing the setpoint speed


// For the Engineer

ezButton joystick(2);


  char *station[10] = {"Carnegie","Bell","Inglewood","Crafton","Ingram","Sheraden","Allegheny","North Side","Gateway Center","Wood Street"};
  // define variable for current station
  char *currStation;
  
  // define variables for state of doors and lights
  bool doors, interiorLights, exteriorLights;

  
  // define variable for setpoint
  float setpoint = 0;

  
  // define variables for authority and suggested speed
  float authority = 300; 
  float suggested_speed = 50;

  
  // define variables for commanded speed and commanded power
  float commanded_speed, commanded_power;



  // define variable speed limit
  float speed_limit = 40;

  // define Kp and Ki for the engineers to set
  float Kp = 0;
  float Ki = 0;

  // define Kp and Ki that the train currently is using
  float Kptrain, Kitrain;
    
  int x = 0;  

void setup() {
  // put your setup code here, to run once:



  Serial.begin(9600);




  // initialize digital pin 11 as an output
  pinMode(11, OUTPUT);

  // initialize digital pin 13 as an output
  pinMode(13, OUTPUT);


  
  buttonDoors.setDebounceTime(50);
  buttonLights.setDebounceTime(50);

  setSetpoint.setDebounceTime(50);
  incrSetpoint.setDebounceTime(50);
  decrSetpoint.setDebounceTime(50);


}

int i = 0;
void loop() {
  // put your main code here, to run repeatedly:

  currStation = station[i];
  i++;
  if (i == 9) {
    i = 0;  
  }


// For the Train Driver

  // Check if button for increasing setpoint is pressed
  incrSetpoint.loop();

  if (incrSetpoint.isPressed()) {
    Serial.println("The increasing setpoint button is pressed.");
    setpoint += 5;
    delay(1000);
    
    Serial.print("The new setpoint is: ");
    Serial.println(setpoint);
    delay(1000);
  }

  // Check if button for decreasing setpoint is pressed
  decrSetpoint.loop();
  
  if (decrSetpoint.isPressed())  {
    Serial.println("The decreasing setpoint button is pressed.");
    delay(1000);
    if (setpoint >= 5)
      setpoint -= 5;
    else
      Serial.println("Decreasing the setpoint by 5 mph would result in a negative setpoint, which is not allowed.");

    Serial.print("The new setpoint is: ");
    Serial.println(setpoint);
    delay(1000);
  }

  // Check if button for setting setpoint is pressed
  setSetpoint.loop();

  if (setSetpoint.isPressed()) {
      Serial.println("The setting setpoint button is pressed.");
    
    
      if (setpoint <= speed_limit && setpoint > 0) {
          // communicate that the new setpoint is acceptable and under the speed limit
          Serial.println("The new setpoint is an acceptable speed, and the commanded speed will be updated.");
          delay(1000);
          digitalWrite(13, HIGH);
          delay(500);
          digitalWrite(13, LOW);
          delay(500);
          commanded_speed = setpoint; 
      }
      else {
          Serial.println("The new setpoint is not an acceptable speed, it's above the speed limit! The commanded speed will be updated to the speed limit.");
          delay(1000);
          digitalWrite(11, HIGH);
          delay(500);
          digitalWrite(11, LOW);
          delay(500);
          commanded_speed = speed_limit;
        
      }
    
    }
    
      
    

  // Check if doors open/close button is pressed

  buttonDoors.loop();

  if (buttonDoors.isPressed()) {
    Serial.println("The doors open/close button is pressed.");
    doors = !doors;
    if (doors == 0)
    // communicate that the doors are closing
      Serial.println("Doors are closing.");  
    if (doors == 1)
      Serial.println("Doors are opening.");

      delay(1000);
  }

  // Check if Lights on/off button is pressed

  buttonLights.loop();

  if(buttonLights.isPressed()) {
    
    interiorLights = !interiorLights;
    exteriorLights = !exteriorLights;  

    Serial.println("The lights button is pressed");

    delay(1000);
    
  }
    



  // For the Engineer

  // Check if increase Kp is selected on joystick
  int xValue = analogRead(A0);
  int yValue = analogRead(A1);

  if (xValue > 2.5)
    Kp += 0.5;


  // Check if decrease Kp is selected on joystick
  
  if (xValue < 2.5)
    Kp -= 0.5;


  // Check if set Kp is pressed on joystick

  joystick.loop();
  
  if (joystick.isPressed())
    Kptrain = Kp;





  // Check if increase Ki selected on joystick
  
  if (yValue > 2.5)
    Ki += 0.5;


  // Check if decrease Ki selected on joystick
  
  if (yValue < 2.5)
    Ki -= 0.5;


  // Check if set Ki pressed on joystick

  joystick.loop();
  
  if (joystick.isPressed())
    Kitrain = Ki;





  

  x++;
  if (x == 1000) {
  x = 0;




  
  // send and print out the states of everything, make sure everything is communicated

  Serial.println("Suggested Speed");
  Serial.println(suggested_speed);
  Serial.println("mph");

  // print state of doors
  Serial.print("The doors are ");
  if (doors) {
    Serial.println("open");
  }
  else
  {
    Serial.println("closed");  
  }


  // print state of lights
  Serial.print("The interior lights are ");

    if (interiorLights) {
      Serial.println("on");  
    
    }
    else {
      Serial.println("off");  
    }

  Serial.print("The exterior lights are ");
    if (exteriorLights) {
      Serial.println("on");
      
    }
    else {
      Serial.println("off");  
    }



  // print suggested speed
  Serial.print("The suggested speed is ");
  Serial.print(suggested_speed);
  Serial.println("mph");
  


  // print authority
  Serial.print("The authority is ");
  Serial.print(authority);
  Serial.println("m");
  

  // print speed limit
  Serial.print("The speed limit is ");
  Serial.print(speed_limit);
  Serial.println("mph");
  
  // print commanded power
  Serial.print("The Commanded Power is ");
  Serial.print(commanded_power);
  Serial.println("kW");

  Serial.print("The Commanded Speed is ");
  Serial.print(commanded_speed);
  Serial.println("mph");

  Serial.print("The Kp is ");
  Serial.println(Kptrain);
  Serial.print("The Ki is ");
  Serial.println(Kitrain);
  Serial.println();



  Serial.print("The current station is ");
  // announce the current station
  Serial.println(currStation);
  }
  
  delay(10);

}
