const auto buttonPin = D4;
const auto buttonPowerPin = D6;
CANChannel can(CAN_D1_D2);
const auto canSpeed = 500000;

void setup() {
  pinMode(buttonPowerPin, OUTPUT);
  digitalWrite(buttonPowerPin, HIGH);
  pinMode(buttonPin, INPUT_PULLDOWN);
  pinMode(D7, OUTPUT);
  can.begin(canSpeed);
}

void loop() {
  bool button = digitalRead(buttonPin);
  digitalWrite(D7, button);
  CANMessage message;

  message.id = 0x100;
  message.len = 1;
  message.data[0] = button;

  can.transmit(message);

  delay(100);
}
