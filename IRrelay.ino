#include "src/IRremote/IRremote.h"

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

void dump(decode_results * results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.println("Could not decode message");
  } else {
    if (results->decode_type == NEC) {
      Serial.print("Decoded NEC: ");
    } else if (results->decode_type == SONY) {
      Serial.print("Decoded SONY: ");
    } else if (results->decode_type == RC5) {
      Serial.print("Decoded RC5: ");
    } else if (results->decode_type == RC6) {
      Serial.print("Decoded RC6: ");
    }
    Serial.print(results->value, HEX);
    Serial.print(" (");
    Serial.print(results->bits, DEC);
    Serial.println(" bits)");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");

  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    } else {
      Serial.print(-(int) results->rawbuf[i] * USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}

void setup() {
  ///Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int on = 0;
unsigned long last = millis();

void loop() {

  if (irrecv.decode( & results)) {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    ///dump(&results);

    if ((results.value == 0xE0E040BF || results.value == 0x753CD54D) && millis() - last > 250) {
      ////Serial.println("2");
      last = millis();

      unsigned int rawData[] = {9000,4600, 400,650, 500,650, 450,700, 400,700, 450,650, 450,700, 400,700, 450,650, 450,1800, 450,1800, 450,1800, 400,1800, 450,1850, 400,1800, 450,1800, 450,650, 450,650, 450,1800, 450,650, 450,1800, 450,700, 450,650, 450,650, 450,700, 450,1800, 400,700, 450,1800, 400,700, 450,1800, 400,1850, 450,1800, 400,1800, 450};
      
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);

      ///Serial.println("6");
    }
    irrecv.resume();
    irrecv.enableIRIn(); // Start the receiver

  }
  delay(50);
}
