#include "pump_service.h"

void PumpService::begin() {
    pinMode(D2, OUTPUT);
    digitalWrite(D2, HIGH);

    pinMode(D0, OUTPUT);
    digitalWrite(D0, HIGH);

    pinMode(D1, OUTPUT);
    digitalWrite(D1, HIGH);

    pinMode(D3, OUTPUT);
    digitalWrite(D3, HIGH);

    pinMode(D4, OUTPUT);
    digitalWrite(D4, HIGH);

    pinMode(D5, OUTPUT);
    digitalWrite(D5, HIGH);

    pinMode(D6, OUTPUT);
    digitalWrite(D6, HIGH);

    pinMode(D7, OUTPUT);
    digitalWrite(D7, HIGH);
}

void PumpService::start1() {
    pinMode(D0, OUTPUT);
    digitalWrite(D0, LOW);
}

void PumpService::stop1() {
    pinMode(D0, OUTPUT);
    digitalWrite(D0, HIGH);
}

void PumpService::stop8() {
    pinMode(D7, OUTPUT);
    digitalWrite(D7, HIGH);
}

void PumpService::start8() {
    pinMode(D7, OUTPUT);
    digitalWrite(D7, LOW);
}

void PumpService::stop7() {
    pinMode(D6, OUTPUT);
    digitalWrite(D6, HIGH);
}

void PumpService::start7() {
    pinMode(D6, OUTPUT);
    digitalWrite(D6, LOW);
}

void PumpService::stop6() {
    pinMode(D5, OUTPUT);
    digitalWrite(D5, HIGH);
}

void PumpService::start6() {
    pinMode(D5, OUTPUT);
    digitalWrite(D5, LOW);
}

void PumpService::stop5() {
    pinMode(D4, OUTPUT);
    digitalWrite(D4, HIGH);
}

void PumpService::start5() {
    pinMode(D4, OUTPUT);
    digitalWrite(D4, LOW);
}

void PumpService::stop4() {
    pinMode(D3, OUTPUT);
    digitalWrite(D3, HIGH);
}

void PumpService::start4() {
    pinMode(D3, OUTPUT);
    digitalWrite(D3, LOW);
}

void PumpService::stop3() {
    pinMode(D2, OUTPUT);
    digitalWrite(D2, HIGH);
}

void PumpService::start3() {
    pinMode(D2, OUTPUT);
    digitalWrite(D2, LOW);
}

void PumpService::stop2() {
    pinMode(D1, OUTPUT);
    digitalWrite(D1, HIGH);
}

void PumpService::start2() {
    pinMode(D1, OUTPUT);
    digitalWrite(D1, LOW);
}
