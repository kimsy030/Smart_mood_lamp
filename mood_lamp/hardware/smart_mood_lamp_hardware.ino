///블루투스 + 네오픽셀

#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6                      // 디지털핀 어디에 연결했는지 입력
#define LEDNUM 8                  // 연결된 네오픽셀의 숫자입력
#define BRIGHTNESS 50               // 네오픽셀의 밝기를 설정합니다. (0~255)
//첫번째 인자값은 네오픽셀의 LED의 개수
//두번째 인자값은 네오픽셀이 연결된 아두이노의 핀번호
//세번째 인자값은 네오픽셀의 타입에 따라 바뀌는 flag
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRBW + NEO_KHZ800);

String Str = "";
char data;
int RX=7;
int TX=8;

SoftwareSerial bluetooth(RX, TX);

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  strip.setBrightness(BRIGHTNESS);
}
/*
void loop(){
  strip.begin();                           // 네오픽셀 제어시작
  strip.show();      
    while(bluetooth.available()) { //if received Bluetooth data
        char mychar = (char)bluetooth.read(); //save char in buffer
        Str += mychar; //save buffer data to Str
        delay(100);
    }
    if (!Str.equals("")) {   //print Str at enter
            Serial.println(Str);

             if(Str == "o"){
                strip.setPixelColor(0, 0, 0, 0, 200);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
                strip.setPixelColor(1, 0, 0, 0, 200);
                strip.setPixelColor(2, 0, 0, 0, 200);
                strip.setPixelColor(3, 0, 0, 0, 200);
                strip.setPixelColor(4, 0, 0, 0, 200);
                strip.setPixelColor(5, 0, 0, 0, 200);
                strip.setPixelColor(6, 0, 0, 0, 200);
                strip.setPixelColor(7, 0, 0, 0, 200);
             }
             else if(Str == "c"){
                strip.setPixelColor(0, 0, 0, 0, 0);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
                strip.setPixelColor(1, 0, 0, 0, 0);
                strip.setPixelColor(2, 0, 0, 0, 0);
                strip.setPixelColor(3, 0, 0, 0, 0);
                strip.setPixelColor(4, 0, 0, 0, 0);
                strip.setPixelColor(5, 0, 0, 0, 0);
                strip.setPixelColor(6, 0, 0, 0, 0);
                strip.setPixelColor(7, 0, 0, 0, 0);
           
            }
          Str = "";
    }
}*/

void loop() {
  if(bluetooth.available()){
    data = bluetooth.read();
    delay(5);
    strip.begin();                           // 네오픽셀 제어시작
    strip.show();                            // 네오픽셀 초기화
    Serial.write(data); // 시리얼 모니터에 데이터 출력
    //자동모드
    
    if(data == 'c'){
        strip.setPixelColor(0, 0, 0, 0, 200);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
        strip.setPixelColor(1, 0, 0, 0, 200);
        strip.setPixelColor(2, 0, 0, 0, 200);
        strip.setPixelColor(3, 0, 0, 0, 200);
        strip.setPixelColor(4, 0, 0, 0, 200);
        strip.setPixelColor(5, 0, 0, 0, 200);
        strip.setPixelColor(6, 0, 0, 0, 200);
        strip.setPixelColor(7, 0, 0, 0, 200);
    }
    else if(data == 'o'){
       strip.setPixelColor(0, 0, 0, 0, 0);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 0);
       strip.setPixelColor(2, 0, 0, 0, 0);
       strip.setPixelColor(3, 0, 0, 0, 0);
       strip.setPixelColor(4, 0, 0, 0, 0);
       strip.setPixelColor(5, 0, 0, 0, 0);
       strip.setPixelColor(6, 0, 0, 0, 0);
       strip.setPixelColor(7, 0, 0, 0, 0);
    }
    //캠핑모드
    if(data == 'm'){
       strip.setPixelColor(0, 0, 0, 0, 150);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 150);
       strip.setPixelColor(2, 0, 0, 0, 150);
       strip.setPixelColor(3, 0, 0, 0, 150);
       strip.setPixelColor(4, 0, 0, 0, 150);
       strip.setPixelColor(5, 0, 0, 0, 150);
       strip.setPixelColor(6, 0, 0, 0, 150);
       strip.setPixelColor(7, 0, 0, 0, 150);
    }
    else if(data == 'n'){
       strip.setPixelColor(0, 0, 0, 0, 10);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 10);
       strip.setPixelColor(2, 0, 0, 0, 10);
       strip.setPixelColor(3, 0, 0, 0, 10);
       strip.setPixelColor(4, 0, 0, 0, 10);
       strip.setPixelColor(5, 0, 0, 0, 10);
       strip.setPixelColor(6, 0, 0, 0, 10);
       strip.setPixelColor(7, 0, 0, 0, 10);
        
    }
    //수면모드
    if(data == 's'){
       strip.setPixelColor(0, 0, 0, 0, 190);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 190);
       strip.setPixelColor(2, 0, 0, 0, 190);
       strip.setPixelColor(3, 0, 0, 0, 190);
       strip.setPixelColor(4, 0, 0, 0, 190);
       strip.setPixelColor(5, 0, 0, 0, 190);
       strip.setPixelColor(6, 0, 0, 0, 190);
       strip.setPixelColor(7, 0, 0, 0, 190);
    }
    else if(data == 'l'){
       strip.setPixelColor(0, 0, 0, 0, 10);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 10);
       strip.setPixelColor(2, 0, 0, 0, 10);
       strip.setPixelColor(3, 0, 0, 0, 10);
       strip.setPixelColor(4, 0, 0, 0, 10);
       strip.setPixelColor(5, 0, 0, 0, 10);
       strip.setPixelColor(6, 0, 0, 0, 10);
       strip.setPixelColor(7, 0, 0, 0, 10);
    }
    //독서모드
    if(data == 'r'){
        strip.setPixelColor(0, 0, 0, 0,210);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 210);
       strip.setPixelColor(2, 0, 0, 0, 210);
       strip.setPixelColor(3, 0, 0, 0, 210);
       strip.setPixelColor(4, 0, 0, 0, 210);
       strip.setPixelColor(5, 0, 0, 0, 210);
       strip.setPixelColor(6, 0, 0, 0, 210);
       strip.setPixelColor(7, 0, 0, 0, 210);
    }
    else if(data == 'd'){
       strip.setPixelColor(0, 0, 0, 0, 10);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
       strip.setPixelColor(1, 0, 0, 0, 10);
       strip.setPixelColor(2, 0, 0, 0, 10);
       strip.setPixelColor(3, 0, 0, 0, 10);
       strip.setPixelColor(4, 0, 0, 0, 10);
       strip.setPixelColor(5, 0, 0, 0, 10);
       strip.setPixelColor(6, 0, 0, 0, 10);
       strip.setPixelColor(7, 0, 0, 0, 10);
    }
  }
}
/*
//네오픽셀 테스트
#include <Adafruit_NeoPixel.h>   // 네오픽셀 라이브러리를 불러옵니다.

#define PIN 6                      // 디지털핀 어디에 연결했는지 입력
#define LEDNUM 8                  // 연결된 네오픽셀의 숫자입력
#define BRIGHTNESS 50               // 네오픽셀의 밝기를 설정합니다. (0~255)
//첫번째 인자값은 네오픽셀의 LED의 개수
//두번째 인자값은 네오픽셀이 연결된 아두이노의 핀번호
//세번째 인자값은 네오픽셀의 타입에 따라 바뀌는 flag
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.setBrightness(BRIGHTNESS);
}

void loop() {                              // 이 안에 입력한 내용들이 반복 실행됩니다
  strip.begin();                           // 네오픽셀 제어시작
  strip.show();                            // 네오픽셀 초기화
  strip.setPixelColor(0, 0, 0, 0, 0);     // (A,R,G,B,W) A번째 LED를 RGBW (0~255) 만큼의 밝기로 켭니다.
  strip.setPixelColor(1, 0, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0, 0);
  strip.setPixelColor(5, 0, 0, 0, 0);
  strip.setPixelColor(6, 0, 0, 0, 0);
  strip.setPixelColor(7, 0, 0, 0, 0);
  
}*/

//블루투스 테스트
/*
#include <SoftwareSerial.h>

int RX=7;
int TX=8;
String Str;
SoftwareSerial bluetooth(RX, TX);

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop(){  
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}*/
