const auto ledPin = A3;
const auto ledPowerPin = A6;
CANChannel can(CAN_D1_D2);
const auto canSpeed = 500000;

void setup() {
  pinMode(ledPowerPin, OUTPUT);
  digitalWrite(ledPowerPin, HIGH);
  pinMode(ledPin, OUTPUT);
  can.begin(canSpeed);
}

void loop() {
  CANMessage message;

  while(can.receive(message)) {
    if (message.id == 0x100) {
      digitalWrite(ledPin, !message.data[0]);
    }
  }

  delay(100);
}

