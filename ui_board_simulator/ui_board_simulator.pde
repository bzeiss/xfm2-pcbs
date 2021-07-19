import controlP5.*;
import processing.serial.*;

Serial port;

ControlP5 cp5;
PFont font;

Button upButton;
Button downButton;
Button leftButton;
Button rightButton;
Button enterButton;

void setup(){

  size(300, 300);
  
//  printArray(PFont.list());
  printArray(Serial.list());
  
  port = new Serial(this, "COM3", 9600);
  
  cp5 = new ControlP5(this);
  font = createFont("Arial", 20);
  
  upButton=cp5.addButton("up")
    .setPosition(100, 50)
    .setSize(100, 50)
    .setFont(font)
  ;   

  downButton=cp5.addButton("down")
    .setPosition(100, 150)
    .setSize(100, 50)
    .setFont(font)
  ;

  leftButton=cp5.addButton("left")
    .setPosition(30, 100)
    .setSize(100, 50)
    .setFont(font)  ;
  
  rightButton=cp5.addButton("right")
    .setPosition(170, 100)
    .setSize(100, 50)
    .setFont(font)  ;
  
  enterButton=cp5.addButton("enter")
    .setPosition(30, 230)
    .setSize(250, 50)
    .setFont(font)
  ;  
}

void draw() {
  background(150, 150 , 150);
  
  fill(0, 0, 0);
  textFont(font);
  text("XFM2/XVA UI Board Simulator", 15, 30);
}

void keyPressed() {
//  print(keyCode);
  if (keyCode == 38) { // up
    up();
  } else if (keyCode == 40) { // down
    down();
  } else if (keyCode == 37) { // left
    left();
  } else if (keyCode == 39) { // right
    right();
  } else if (keyCode == 10) { // enter
    enter();
  }
}

void up(){
  println("up");
  port.write('u');
}

void down(){
  port.write('d');
}

void left(){
  port.write('l');
}

void right(){
  port.write('r');
}

void enter(){
  port.write('e');
}
