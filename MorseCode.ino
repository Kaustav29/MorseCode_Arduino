// Define the LED pins
const int dotLedPin = 7; // Dot LED on pin 13
const int dashLedPin = 8; // Dash LED on pin 12

// Define the Morse code timings (in milliseconds)
const int dotDuration = 150; // Duration of a dot
const int dashDuration = 3 * dotDuration; // Duration of a dash
const int interElementPause = dotDuration; // Pause between elements of the same letter
const int interLetterPause = 3 * dotDuration; // Pause between letters
const int interWordPause = 7 * dotDuration; // Pause between words

void setup() {
  // Initialize the LED pins as outputs
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  //Morse code for "HELLO WORLD"
  const char* morseCode = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

  // Loop through each character in the Morse code string
  for (int i = 0; morseCode[i] != '\0'; i++) {
    // Check if the character is a dot or dash
    if (morseCode[i] == '.') {
      // Blink the dot LED
      blink(dotLedPin, dotDuration);
      delay(interElementPause);
    } else if (morseCode[i] == '-') {
      // Blink the dash LED
      blink(dashLedPin, dashDuration);
      delay(interElementPause);
    } else if (morseCode[i] == ' ') {
      // Pause between words
      delay(interWordPause);
    } else if (morseCode[i] == '/') {
      // Pause between letters
      delay(interLetterPause);
    }
  }

  // Pause at the end of the Morse code sequence
  delay(interWordPause * 3);
}

// Function to blink an LED for a specified duration
void blink(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}
