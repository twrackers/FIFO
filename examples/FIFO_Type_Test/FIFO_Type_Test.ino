// This sketch performs a running mean of a series of random integer values
// by storing the last `NUMVALS` values in a FIFO of 16-bit unsigned integers,
// and keeping a running sum of those values in global variable `accum`.  Each 
// time a new random value is generated, the oldest value in the FIFO is popped
// off the front of the FIFO and subtracted from the running sum.  Then the new
// is pushed onto the back of the FIFO and added to the running sum.  The running
// mean is the running sum divided by the capacity of the FIFO.

#include <FIFO_Type.h>

typedef uint16_t data_t;

#define NUMVALS 50
FIFO_Type<data_t> wfifo(NUMVALS);

void setup() {

  Serial.begin(115200);
  while (!Serial) delay(10);
  
  randomSeed(analogRead(A0));
  
}

// Running sum of FIFO contents
data_t accum = 0;

void loop() {

  // If FIFO is full, pop value from front and subtract it from
  // running sum.
  if (wfifo.isFull()) {
    accum -= wfifo.pop();
  }
  // Generate a new value.
  data_t newval = (data_t) random(1000);
  // Add new value to running sum, and push it onto back of FIFO.
  accum += newval;
  wfifo.push(newval);
  // Print new value and the running mean of the stored values.
  Serial.print(newval);
  Serial.print(' ');
  Serial.println(accum / NUMVALS);

  delay(20);
  
}
