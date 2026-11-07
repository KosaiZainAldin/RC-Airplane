void setup() {
    pinMode(A1, INPUT);
    pinMode(3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int input;
    double output;
    double adjuster;

    // Read the analog throttle input.
    input = analogRead(A1);
    Serial.print(input);
    Serial.println(" ");
    delay(100);

    // Keep the motor off below the throttle midpoint.
    if (input <= 512) {
        output = 0;
    }

    // Gradually increase PWM as the throttle input increases.
    else if (input > 512 && input < 1023) {
        // Set the minimum PWM value needed to start the motor.
        output = 104.5;

        // Scale the throttle input into a gradual PWM adjustment.
        adjuster = (input - 512) / 3.41;
        output = output + adjuster;
    }

    // Set maximum PWM at full throttle.
    else {
        output = 255;
    }

    analogWrite(3, output);
}
