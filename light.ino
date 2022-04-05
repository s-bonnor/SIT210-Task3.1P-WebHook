#define PinA A0
#define PinB A1

SYSTEM_THREAD(ENABLED);

void setup() {
    Serial.begin(115200);

    pinMode(PinA, OUTPUT);
    pinSetFast(PinA);

    delay(1000);
    Serial.println("-------RESET-------");
}

void loop() {
    if (!Particle.connected()) {
        return;
    }
    int result = analogRead(PinB);
    Serial.printlnf("Status: %i", result);
    Particle.publish("light", String(result), PRIVATE);
    delay(15000);
}