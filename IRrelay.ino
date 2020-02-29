#include "src/IRremote/IRremote.h"

int RECV_PIN = 0;

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
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int on = 0;
unsigned long last = millis();

void loop() {
  Serial.println("Waiting for input...");

  if (irrecv.decode( & results)) {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    dump(&results);

    if ((results.value == 0xE0E040BF || results.value == 0x753CD54D) && millis() - last > 250) {
      Serial.println("2");
      last = millis();

// TODO
      unsigned int rawData[] = {4550,4400,600,1650,550,1650,600,1650,550,550,600,500,600,550,550,550,600,500,600,1650,600,1600,600,1650,550,550,600,500,600,550,600,500,600,500,650,450,650,1600,600,500,650,450,650,500,600,500,600,500,600,550,600,1600,600,500,650,1600,650,1550,650,1600,650,1550,650,1600,650,1600,600}; 
      
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);
      irsend.sendRaw(rawData, sizeof(rawData) / sizeof(int), 38);
      delay(40);

      Serial.println("6");
    }
    irrecv.enableIRIn(); // Start the receiver

  }
}
