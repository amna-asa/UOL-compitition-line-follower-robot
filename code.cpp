
```C++
//right motor
int r_enR = 30;
int l_enR= 28;
int r_forward = 4;
int r_backword = 5;  

//left motor
int r_enL= 32;
int l_enL = 34;
int l_forward= 3;
int l_backword = 2;

//sensors code
int smrv=12;
int srv=11;
int scv=10;
int slv=9;
int smlv=8;

//speeds control
int speed=100;
int turn=100;
int slow=100;
int stop=0;

//sensor logic
int black=0;
int white=1;

int pass = 0;

//logic flags
bool allblack = false;
bool allwhite =false;

int count=0;

int smr, sr, sc, sl, sml = 0;

void read_sensor()
{
  smr=digitalRead(smrv);
  sr=digitalRead(srv);
  sc=digitalRead(scv);
  sl=digitalRead(slv);
  sml=digitalRead(smlv);
}

void setup(){

 Serial.begin(9600);
 
 pinMode(30,OUTPUT);
 pinMode(28,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(32,OUTPUT);
 pinMode(34,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 digitalWrite(30,HIGH);
 digitalWrite(28,HIGH);
 digitalWrite(32,HIGH);
 digitalWrite(34,HIGH);



 while(1)
 {
  linefollow();
  if(pass == 1)
  {
    break;
  }
 }
 pass = 0;
 halt();
 delay(1000);
 forward();
 delay(700);
 halt();
 delay(1000);
 while(1)
 {
  linefollow();
  if(pass == 1)
  {
    break;
  }
 }


}

void loop(){
}


void linefollow(){
   smr=digitalRead(smrv);
   sr=digitalRead(srv);
   sc=digitalRead(scv);
   sl=digitalRead(slv);
   sml=digitalRead(smlv);

if(sr==white && sc==black && sl==white){
forward();
}
else if(sr==black && sc==black && sl==white){
right();
}
else if(sr==white && sc==black && sl==black){
left();
}
else if(sml == white && sl == white && sc == white && sr == black && smr == white){
right();
}
else if(sml == white && sl == black && sc == white && sr == white && smr == white){
left();
}


else if (sml == 0 && sl == 0 && sc == 0 && sr == 0 && smr == 0) {
  halt();
  pass = 1;
}


}

void forward(){
 analogWrite(r_forward,speed);
 analogWrite(r_backword,stop);
 analogWrite(l_forward,speed);
 analogWrite(l_backword,stop);
}

void backword(){
 analogWrite(r_forward,stop);
 analogWrite(r_backword,speed);
 analogWrite(l_forward,stop);
 analogWrite(l_backword,speed);
}


void halt(){
 analogWrite(r_forward,0);
 analogWrite(r_backword,0);
 analogWrite(l_forward,0);
 analogWrite(l_backword,0);
}

void left(){
 analogWrite(r_forward,turn);
 analogWrite(r_backword,stop);
 analogWrite(l_forward,stop);
 analogWrite(l_backword,stop);
}
void right(){
 analogWrite(r_forward,stop);
 analogWrite(r_backword,stop);
 analogWrite(l_forward,turn);
 analogWrite(l_backword,stop);
}
void left90(){
 analogWrite(r_forward,turn);
 analogWrite(r_backword,stop);
 analogWrite(l_forward,stop);
 analogWrite(l_backword,slow);
}

void right90(){
 analogWrite(r_forward,stop);
 analogWrite(r_backword,slow);
 analogWrite(l_forward,turn);
 analogWrite(l_backword,stop);
}

```