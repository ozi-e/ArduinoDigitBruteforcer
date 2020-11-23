///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SET VARIABLES BETWEEN LINE 2 AND 9
int commandDelay = 150; 
int buttonDelay = 200;
int rotateDelay = 150;
int code = 0; //THIS VARIABLE SETS STARTING CODE
int maxCode = 9999; //THIS VARIABLE SETS MAXIMUM KEY VALUE
const int amountOfDigits = 4;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pos = 0; //Most significant to least significant, most significant having pos=0 and least having pos=3

int ones = 0;
int tens = 0;
int huns = 0;
int thou = 0;
int individualDigits[amountOfDigits];

void BtnUp();
void BtnDown();
void BtnRight();
void BtnEnter();
void NumRotator(int codedigit);
void InitDigit();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  //reinit code
  delay(10000); //Delay before starting, time to set up camera so you know when it's unlocked :)
  code = 0;
  //init digits array
  InitDigit();
  Serial.begin(9600);

  pinMode(8, OUTPUT); //Switch up
  pinMode(9, OUTPUT); //Switch down
  pinMode(10, OUTPUT); //Switch right
  pinMode(11, OUTPUT); //Switch OK
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitDigit()
{
  for(int cla = 0; cla < amountOfDigits; cla++)
  {
    individualDigits[amountOfDigits - cla] = (code/(int)pow(10, cla)) % 10;  //Grab digit digit;
  }
}

void BtnUp()
{
  //Insert up code
  digitalWrite(8, HIGH);
  delay(buttonDelay);
  digitalWrite(8, LOW);
}
void BtnDown()
{
  //Insert down code
  digitalWrite(9, HIGH);
  delay(buttonDelay);
  digitalWrite(9, LOW);
}
void BtnRight()
{
  //Insert right code
  digitalWrite(10, HIGH);
  delay(buttonDelay);
  digitalWrite(10, LOW);
}
void BtnEnter()
{
  //Insert enter code
  digitalWrite(11, HIGH);
  delay(buttonDelay);
  digitalWrite(11, LOW);
}

//REVERSE IF BIGGER THAN 4
void NumRotator(int codedigit)
{
  if(codedigit < 5)
  {
    for (int rotate = 0; rotate <= codedigit; rotate++)
    {
      delay(rotateDelay);
      BtnUp();
    }
  }
  else
  {
    for (int rotate = 9; rotate >= codedigit; rotate--)
    {
      delay(rotateDelay);
      BtnDown();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  for (code; code < maxCode; code++)
  {
    /*Manual way, hard way*/
    /*ones = code % 10; //Grab first digit
    tens = (code/10) % 10;  //Grab second digit
    huns = (code/100) % 10; //Grab third digit
    thou = (code/1000) % 10;  //Grab fourth digit*/
    InitDigits();

    NumRotator(thou);
    delay(commandDelay);
    BtnRight();
    delay(commandDelay);
    NumRotator(huns);
    delay(commandDelay);
    BtnRight();
    delay(commandDelay);
    NumRotator(tens);
    delay(commandDelay);
    BtnRight();
    delay(commandDelay);
    NumRotator(ones);
    delay(commandDelay);
    delay(commandDelay);
    BtnEnter();
    delay(commandDelay);
    delay(commandDelay);
    

    //code++;
    Serial.println(code);
  }
  code = 0; //reset code due to overflow
}
