int read;

float potentRead(int pin);
void rgbWrite(int redPin, int bluePin, int greenPin, int value);
void setColor(int redVal, int greenVal, int blueVal);

void setup()
{
  for (int i = 11; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  read = round(potentRead(A2));
  Serial.println(read);
  
  rgbWrite(13, 12, 11, read);
  
  delay(500);
}

float potentRead(int pin)
{
  return ((float) analogRead(A2) * 255.00) / 1023.00;
}

void rgbWrite(int redPin, int bluePin, int greenPin, int value)
{
  switch (value)
  {
    case 1 ... 51:
    	setColor(HIGH, LOW, LOW);
    	break;
    case 52 ... 102:
    	setColor(HIGH, HIGH, LOW);
    	break;
    case 103 ... 153:
    	setColor(LOW, HIGH, LOW);
    	break;
    case 154 ... 205:
    	setColor(LOW, HIGH, HIGH);
    	break;
    case 206 ... 255:
    	setColor(LOW, LOW, HIGH);
    	break;
  }
}

void setColor(int redVal, int greenVal, int blueVal)
{
    digitalWrite(redPin, redVal);
    digitalWrite(greenPin, greenVal);
    digitalWrite(bluePin, blueVal);
}