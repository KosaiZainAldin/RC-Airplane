void setup() {
    pinMode(A1, INPUT);
    pinMode(3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int input;
    double output;
    double adjuster = input;

    input = analogRead(A1);
    Serial.print(input);
    Serial.println(" ");
    delay(100);

    if (input <= 520) {
        output = 0;
    }
    else if (input > 520 && input < 1023) {
        output = 104.5;
        adjuster = (input - 520) / 12;
        output = output + adjuster;
    }
    else {
        output = 255;
    }

    analogWrite(3, output);
}
