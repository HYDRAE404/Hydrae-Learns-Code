int read;

void setup()
{
  pinMode(A5, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  read = analogRead(A5);

  digitalWrite(13, HIGH);
  delay(read);
  digitalWrite(13, LOW);
  delay(read);
}