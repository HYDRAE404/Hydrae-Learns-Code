int read;

void setup()
{
  // assuming pin A0 is a potentiometer
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // get value from potentiometer
  read = analogRead(A0);

  // display potentiometer value in serial
  Serial.println(read);

  delay(200);
}