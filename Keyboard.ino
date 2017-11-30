int button_C = 2;
int button_D = 3;
int button_E = 4;
int button_F = 5;
int button_G = 6;
int button_A = 7;
int button_B = 8;
int button_Cup = 9;

int speaker = 12;

int buttonstate_C = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;
int buttonstate_G = 0;
int buttonstate_A = 0;
int buttonstate_B = 0;
int buttonstate_Cup = 0;

int a = A0;  //For displaying segment "a"
int b = A1;  //For displaying segment "b"
int c = A2;  //For displaying segment "c"
int d = A3;  //For displaying segment "d"
int e = A4;  //For displaying segment "e"
int f = A5;  //For displaying segment "f"
int g = 10;  //For displaying segment "g"

//NOTES         'c'  , 'd',  'e',  'f',  'g', 'a',  'b',  'C'
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; //freq
int Cur_tone = 0;

void setup()
{
  pinMode(button_C, INPUT);
  pinMode(button_D, INPUT);
  pinMode(button_E, INPUT);
  pinMode(button_F, INPUT);
  pinMode(button_G, INPUT);
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(button_Cup, INPUT);

  pinMode(speaker, OUTPUT);
  
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
}

void loop()
{
	buttonstate_C = digitalRead(button_C);
	buttonstate_D = digitalRead(button_D);
	buttonstate_E = digitalRead(button_E);
	buttonstate_F = digitalRead(button_F);
	buttonstate_G = digitalRead(button_G);
	buttonstate_A = digitalRead(button_A);
	buttonstate_B = digitalRead(button_B);
	buttonstate_Cup = digitalRead(button_Cup);

	if((buttonstate_C == HIGH) || (buttonstate_E == HIGH) ||
		(buttonstate_G == HIGH) || (buttonstate_D == HIGH) ||
		(buttonstate_F == HIGH) || (buttonstate_A == HIGH) ||
		(buttonstate_B == HIGH) || (buttonstate_Cup == HIGH) )
	{
		if (buttonstate_C == HIGH)
		{
			Cur_tone = tones[0];
			digitalWrite(a,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(d,HIGH);
		}
		if (buttonstate_E == HIGH)
		{
			Cur_tone = tones[1];


			digitalWrite(a,HIGH);
			digitalWrite(d,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(g,HIGH);
			digitalWrite(c,HIGH);
			
		}
		if (buttonstate_G == HIGH)
		{
			Cur_tone = tones[2];
digitalWrite(a,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(d,HIGH);
			digitalWrite(b,HIGH);

			
		}
		if (buttonstate_D == HIGH)
		{
			Cur_tone = tones[3];
			digitalWrite(a,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(b,HIGH);
			
			
		}
		if (buttonstate_F == HIGH)
		{
			Cur_tone = tones[4];
			
			
			digitalWrite(a,HIGH);
			digitalWrite(c,HIGH);
			digitalWrite(d,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(b,HIGH);
			
			
		}
		if (buttonstate_A == HIGH)
		{
			Cur_tone = tones[5];
			digitalWrite(a,HIGH);
			digitalWrite(g,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(b,HIGH);
			digitalWrite(c,HIGH);
		}
		if (buttonstate_B == HIGH)
		{
			Cur_tone = tones[6];
			digitalWrite(a,HIGH);
			digitalWrite(b,HIGH);
			digitalWrite(c,HIGH);
			digitalWrite(d,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(g,HIGH);
		}
		if (buttonstate_Cup == HIGH)
		{
			Cur_tone = tones[7];
			digitalWrite(a,HIGH);
			digitalWrite(f,HIGH);
			digitalWrite(e,HIGH);
			digitalWrite(d,HIGH);
		}

		digitalWrite(speaker, HIGH);
		delayMicroseconds(Cur_tone);
		digitalWrite(speaker, LOW);
		delayMicroseconds(Cur_tone);
	}
	else //in case no button is pressed , close the piezo
	{
		digitalWrite(speaker, LOW);
		digitalWrite(a,LOW);
			digitalWrite(b,LOW);
			digitalWrite(c,LOW);
			digitalWrite(d,LOW);
			digitalWrite(e,LOW);
			digitalWrite(f,LOW);
			digitalWrite(g,LOW);
	}

}
