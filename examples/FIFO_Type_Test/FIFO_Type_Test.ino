#include <Streaming.h>

#include <FIFO_Type.h>

#define NUMVALS 50

typedef uint32_t data_t;

FIFO_Type<data_t> wfifo(NUMVALS);

void setup() {

  Serial.begin(115200);
  while (!Serial) delay(10);
  
  randomSeed(analogRead(A0));
  
}

data_t accum = 0;

void loop() {

  if (wfifo.isFull()) {
    accum -= wfifo.pop();
  }
  data_t newval = (data_t) random(1000);
  accum += newval;
  wfifo.push(newval);
  Serial << newval << " " << (accum / NUMVALS) << endl;

  delay(20);
  
}
