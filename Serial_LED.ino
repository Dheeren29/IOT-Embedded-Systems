const int LED = D3;
char inchar;

void setup()
{ Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);}

void loop()
{if (Serial.available())
  {inchar = Serial.read();
    if (inchar == 'A')
    {Serial.println("ON State");
      digitalWrite(LED, HIGH);
    }
    else if (inchar == 'B')
    {Serial.println("OFF State");
      digitalWrite(LED, LOW);
    }
    delay(100);
  }
}
