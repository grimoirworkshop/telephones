# telephones


the working and tested version is from about a month ago; right before a big gap in commit dates
to build in platformIO

OneButton button1(2, true);
OneButton button2(3, true);
OneButton button3(0, true);
OneButton button4(5, true);
these are from buttons on the wall

OneButton button11(9, true);
OneButton button12(8, true);
OneButton button13(7, true);
OneButton button14(12, true);
these are buttons in telephone (LOW when hanged)

outputs are relays

works as follows: on button press starts ringing, closes relay to telephone assosiated with that button so only that tel recieves sound from player
on picking up phone plays assosiated with that phone clip - one can hear it only if the right tel is picked up as relay stays the same way, on hanging the phone opens relay 
problem is player doesnt connect to arduino
problem might be in corrupted card, in fact that dfrobot does not support cards over 32 gb, or faulty player
might be bad cabling though i checked all connections and they seem to be fine
player works by itself perfectly well

Good luck
