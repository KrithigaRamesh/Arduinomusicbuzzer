/*
 Melody "Varaha Roopam

 Plays a melody

 circuit:
 *8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 27 Nov 2023
 by Krithiga Ramesh

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define sa  2093
#define ri  2217
#define ga  2637
#define ma  2793
#define pa  3135


// notes in the melody:
int melody[] = {
  pa,0,pa,ma,ga,ri,sa,0,ma,ga,ri,sa,ma,ga,ri,sa,0,ga,ri,sa,0,ri,sa,0,sa,ri,ga,ma
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  6,6,4,6,6,6,6,6,4,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6
};

void setup() {
  
  int i=0;
  while(i<2) //Tune is iterated twice for improved bgm
  {
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 30; thisNote++)
  {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
    i++;
  }

}

void loop() {
  // no need to repeat the melody.
}
