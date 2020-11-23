
# ArduinoDigitBruteforcer

### Introduction
This is a versatile code template that loops through an x-digit (currently 4) code.
For educational purposes only.

### How this was tested
Paired program with [CD4066BCN quad bilateral switch](https://www.alldatasheet.com/datasheet-pdf/pdf/50858/FAIRCHILD/CD4066BCN.html) connected to both poles of each of an IR-remote's buttons. A separate arduino has a code set up as 4-digit access key.

Buttons up/down change the selected digit value
Button right selects the following digit
Button OK applies key

Code is set up in a way that the key rolls back if the digit value is over 5. This speeds up the process *tremendously*.


