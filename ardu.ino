int ledG=13;
int ledY=12;
int ledR=11;

void setup()
{
    pinMode(ledG, OUTPUT);
    pinMode(ledY, OUTPUT);
    pinMode(ledR, OUTPUT);
}

void loop() 
{
    digitalWrite(ledR, HIGH);
    delay(5000);
    digitalWrite(ledY, HIGH);

    delay(2000);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, HIGH);

    delay(5000);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);

    delay(2000);
    digitalWrite(ledY, LOW);
}