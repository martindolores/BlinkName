int PUSH_BUTTON = D6;
const pin_t LED = D7;
const int dot = 1000;
const int dash = 3000;

SYSTEM_THREAD(ENABLED);

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(PUSH_BUTTON, INPUT_PULLUP);
} 

void space(int btnState)
{
    //Space between letters
    if (btnState != digitalRead(PUSH_BUTTON))
    {
        delay(6s);    
    }
    else
    {
        restart();
    }
}

void flash(int morseTime, int btnState)
{
    //Check between LED blinks to see if user has pressed button
    checkBtnState(btnState);
    digitalWrite(LED, HIGH);
    checkBtnState(btnState);
    delay(morseTime);
    checkBtnState(btnState);
    digitalWrite(LED, LOW);
    checkBtnState(btnState);
    delay(1s); 
    checkBtnState(btnState);
}

void checkBtnState(int btnState)
{
    //Restart if user has pressed button
    if (btnState = digitalRead(PUSH_BUTTON))
    {
       restart(); 
    }
}

void restart()
{
    //Flash LED to indicate morse code is being reset
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200); 
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200); 
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200); 
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(1000);  
    morse(HIGH);
}


void morse(int btnState)
{
    // Morse code for "M"
    flash(dash, btnState);
    flash(dash, btnState);
     
    // Space between the letters
    space(btnState);
      
    // Morse code for "A"
    flash(dot, btnState);
    flash(dash, btnState);
      
    // Space between the letters
    space(btnState);
    
    // Morse code for "R"
    flash(dot, btnState);
    flash(dash, btnState);
    flash(dash, btnState);
        
    // Space between the letters
    space(btnState);
    
    // Morse code for "T"
    flash(dash, btnState);
    
    // Space between the letters
    space(btnState);
    
    // Morse code for "I"
    flash(dot, btnState);
    flash(dot, btnState);
    
    // Space between the letters
    space(btnState);
    
    // Morse code for "N"
    flash(dash, btnState);
    flash(dot, btnState);
}

void loop() 
{
    int currentBtnState = digitalRead(PUSH_BUTTON);
    if (currentBtnState == HIGH) 
    {
        morse(currentBtnState);
    }
}