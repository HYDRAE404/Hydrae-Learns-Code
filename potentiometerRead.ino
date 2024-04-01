int read;

void setup()
{
  // assuming pin 3 is a potentiometer
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // get value from potentiometer
  read = analogRead(3);

  // display potentiometer value in serial
  Serial.println(read);

  delay(200);
}