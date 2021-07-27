import controlP5.*;
import processing.serial.*;

Serial port;

ControlP5 cp5;
PFont font;


// http://www.sojamo.de/libraries/controlP5/#resources
// button size=66,57
// screen size=700,270 // 240,64
// f-key35,20


Button voiceButton;
Button multiButton;
Button utilityButton;
Button editcmpButton;
Button copyButton;
Button memoryButton;

Button effectsBypassButton;

Button shiftButton;
Button f1Button;
Button f2Button;
Button f3Button;
Button f4Button;
Button f5Button;
Button f6Button;
Button f7Button;
Button f8Button;
Button exitButton;

Slider dataEntrySlider;

Button bankSelectButton;
Button elementButton;
Button operatorButton;
Button pageLeftButton;
Button pageRightButton;
Button jumpMarkButton;
Button noMinusOneButton;
Button upButton;
Button yesPlusOneButton;
Button leftButton;
Button downButton;
Button rightButton;

Button numPadSevenButton;
Button numPadEightButton;
Button numPadNineButton;
Button numPadFourButton;
Button numPadFiveButton;
Button numPadSixButton;
Button numPadOneButton;
Button numPadTwoButton;
Button numPadThreeButton;
Button numPadZeroButton;
Button numPadMinusButton;
Button numPadEnterButton;

void setupLeftControls() {   
  voiceButton=cp5.addButton("voice")
    .setPosition(50, 50)
    .setSize(60, 60)
    .setFont(font)
  ;   
  multiButton=cp5.addButton("multi")
    .setPosition(115, 50)
    .setSize(60, 60)
    .setFont(font)
  ;   
  utilityButton=cp5.addButton("utility")
    .setPosition(180, 50)
    .setSize(60, 60)
    .setFont(font)
  ;   
  editcmpButton=cp5.addButton("edit")
    .setPosition(50, 120)
    .setSize(60, 60)
    .setFont(font)
  ;   
  copyButton=cp5.addButton("copy")
    .setPosition(115, 120)
    .setSize(60, 60)
    .setFont(font)
  ;   
  memoryButton=cp5.addButton("memory")
    .setPosition(180, 120)
    .setSize(60, 60)
    .setFont(font)
  ;   

  effectsBypassButton=cp5.addButton("efBypass")
    .setPosition(50, 200)
    .setSize(60, 60)
    .setFont(font)
  ;   

}

void setupMidControls() {
  
  dataEntrySlider=cp5.addSlider("dataEntry")
     .setPosition(720,50)
     .setSize(40,200)
     .setRange(0,128)
     .setValue(0)
     ;

  int xStart = 232;
  int fButtonSizeX=35;
  int fButtonSizeY=20;
  int yOffset = 205;
  int spacing = 8;
  int buttonNo = 1;

  shiftButton=cp5.addButton("shft")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);

  buttonNo++;

  f1Button=cp5.addButton("f1")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);

  buttonNo++;

  f2Button=cp5.addButton("f2")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);
      
  buttonNo++;

  f3Button=cp5.addButton("f3")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);
      
  buttonNo++;

  f4Button=cp5.addButton("f4")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);          
      
  buttonNo++;

  f5Button=cp5.addButton("f5")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);

  buttonNo++;

  f6Button=cp5.addButton("f6")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);       

  buttonNo++;

  f7Button=cp5.addButton("f7")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);

  buttonNo++;
  
  f8Button=cp5.addButton("f8")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);

  buttonNo++;
  
  exitButton=cp5.addButton("ext")
      .setPosition(xStart+buttonNo*fButtonSizeX+buttonNo*spacing, yOffset)
      .setSize(fButtonSizeX, fButtonSizeY)
      .setFont(font);      
}

void setupNavControls() {
  
  int xOffset = 20;
  
  bankSelectButton = cp5.addButton("bank")
      .setPosition(xOffset+770, 50)
      .setSize(60, 60)
      .setFont(font)
    ;   
  elementButton = cp5.addButton("elemnt")
      .setPosition(xOffset+835, 50)
      .setSize(60, 60)
      .setFont(font)
    ;   
  operatorButton = cp5.addButton("operatr")
      .setPosition(xOffset+900, 50)
      .setSize(60, 60)
      .setFont(font)
    ;
    
  pageLeftButton = cp5.addButton("pgLft")
      .setPosition(xOffset+770, 120)
      .setSize(60, 60)
      .setFont(font)
    ;   
  pageRightButton = cp5.addButton("pgRght")
      .setPosition(xOffset+835, 120)
      .setSize(60, 60)
      .setFont(font)
    ;   
  jumpMarkButton = cp5.addButton("jump")
      .setPosition(xOffset+900, 120)
      .setSize(60, 60)
      .setFont(font)
    ;     
  
  noMinusOneButton = cp5.addButton("no")
      .setPosition(xOffset+770, 190)
      .setSize(60, 60)
      .setFont(font)
    ;   
  upButton = cp5.addButton("up")
      .setPosition(xOffset+835, 190)
      .setSize(60, 60)
      .setFont(font)
    ;   
  yesPlusOneButton = cp5.addButton("yes")
      .setPosition(xOffset+900, 190)
      .setSize(60, 60)
      .setFont(font)
    ;     

  leftButton = cp5.addButton("left")
      .setPosition(xOffset+770, 260)
      .setSize(60, 60)
      .setFont(font)
    ;   
  downButton = cp5.addButton("down")
      .setPosition(xOffset+835, 260)
      .setSize(60, 60)
      .setFont(font)
    ;   
  rightButton = cp5.addButton("right")
      .setPosition(xOffset+900, 260)
      .setSize(60, 60)
      .setFont(font)
    ;     

}

void setupNumPadControls() {
  
  int xOffset = 20+190+30;
  
  numPadSevenButton = cp5.addButton("7")
      .setPosition(xOffset+770, 50)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadEightButton = cp5.addButton("8")
      .setPosition(xOffset+835, 50)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadNineButton = cp5.addButton("9")
      .setPosition(xOffset+900, 50)
      .setSize(60, 60)
      .setFont(font)
    ;
    
  numPadFourButton = cp5.addButton("4")
      .setPosition(xOffset+770, 120)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadFiveButton = cp5.addButton("5")
      .setPosition(xOffset+835, 120)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadSixButton = cp5.addButton("6")
      .setPosition(xOffset+900, 120)
      .setSize(60, 60)
      .setFont(font)
    ;     
  
  numPadOneButton = cp5.addButton("1")
      .setPosition(xOffset+770, 190)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadTwoButton = cp5.addButton("2")
      .setPosition(xOffset+835, 190)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadThreeButton = cp5.addButton("3")
      .setPosition(xOffset+900, 190)
      .setSize(60, 60)
      .setFont(font)
    ;     

  numPadZeroButton = cp5.addButton("0")
      .setPosition(xOffset+770, 260)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadMinusButton = cp5.addButton("minus")
      .setPosition(xOffset+835, 260)
      .setSize(60, 60)
      .setFont(font)
    ;   
  numPadEnterButton = cp5.addButton("enter")
      .setPosition(xOffset+900, 260)
      .setSize(60, 60)
      .setFont(font)
    ;     
}

void setup(){

  size(1300, 350);
  
//  printArray(PFont.list());
  printArray(Serial.list());
  
  port = new Serial(this, "COM3", 9600);
  
  cp5 = new ControlP5(this);
  font = createFont("Arial", 12);
    textFont(font);
 
  setupLeftControls();    
  setupMidControls();
  setupNavControls();
  setupNumPadControls();
}

void draw() {
  background(150, 150 , 150);
  
  fill(0, 0, 0);
  font = createFont("Arial", 20);
  textFont(font);
  text("XFM2/XVA UI Board Simulator", 500, 30);
  
  pushMatrix();
  fill(0, 255, 110);
//  rect(255, 50, 480, 200);
  rect(255+60, 90, 340, 110);
  popMatrix();  
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
