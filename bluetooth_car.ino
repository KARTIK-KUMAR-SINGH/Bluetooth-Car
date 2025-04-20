char t;
int en1 = 3;
int en2 = 5;
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;

void setup(){
  pinMode(en1 , OUTPUT);
  pinMode(en2 , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  Serial.begin(9600);
}
void Forward(){
  analogWrite(en2 , 255);
  analogWrite(en1 , 255);
  digitalWrite(in4 , HIGH);
  digitalWrite(in2 , HIGH);
}
void Reverse(){
  analogWrite(en2 , 255);
  analogWrite(en1 , 255);
  digitalWrite(in3 , HIGH);
  digitalWrite(in1 , HIGH);
}
void Left(){
  analogWrite(en1 , 255);
  digitalWrite(in2 , HIGH);
}
void Right(){
  analogWrite(en2 , 255);
  digitalWrite(in4 , HIGH);
}
void Stop(){
  analogWrite(en1 , 0);
  analogWrite(en2 , 0);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , LOW);
}
void loop(){
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
  if (t == 'F') {
    Forward();
  }
  else if(t == 'B') {
    Reverse();
  }
  else if(t == 'L') {
    Left();
  }
  else if(t == 'R') {
    Right();
  }
  else if(t == 'S'){
    Stop();
  }
  delay(10);
}
