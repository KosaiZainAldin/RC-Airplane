void setup() {
    pinMode(A1, INPUT);
    pinMode(3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int input;
    double output;
    double c = a;

    input = analogRead(A1);
    Serial.print(input);
    Serial.println(" ");
    delay(100);

    if (input <= 520) {
        output = 0;
    }
    else {
        output = 104.5;
    }

    c = (input - 516) / 12;
    output = output + c;

    if (input == 1023) {
        output = 255;
    }

    analogWrite(3, output);
}
