
// Code couleur des NEMA 17 <-> brochage sur driver A4988 :
// Vert = 1A
// Bleu = 1B
// Noir = 2A
// Rouge = 2B


// Pinout Moteur NEMA 17 pour l'axe X1
#define pinStepX1   2  // Signal de PAS (avancement)
#define pinMS1X1    22 // Bit 1 de selection du micro pas 
#define pinMS2X1    23 // Bit 2 de selection du micro pas
#define pinMS3X1    24 // Bit 3 de selection du micro pas 
#define pinEnableX1 25 // Activation du driver/pilote
#define pinDirX1    26 // Direction

// Pinout Moteur NEMA 17 pour l'axe Y
#define pinStepY   3  // Signal de PAS (avancement)
#define pinMS1Y    27 // Bit 1 de selection du micro pas 
#define pinMS2Y    28 // Bit 2 de selection du micro pas
#define pinMS3Y    29 // Bit 3 de selection du micro pas 
#define pinEnableY 30 // Activation du driver/pilote
#define pinDirY    31 // Direction

// Pinout Moteur stepper-glissière pour translation selon Z (Seeed)
#define pinStepZ   4  // Signal de PAS (avancement)
#define pinMS1Z    32 // Bit 1 de selection du micro pas 
#define pinMS2Z    33 // Bit 2 de selection du micro pas
#define pinMS3Z    34 // Bit 3 de selection du micro pas 
#define pinEnableZ 35 // Activation du driver/pilote
#define pinDirZ    36 // Direction

// Pinout Moteur NEMA 17 pour l'axe X2
#define pinStepX2   5  // Signal de PAS (avancement)
#define pinMS1X2    37 // Bit 1 de selection du micro pas 
#define pinMS2X2    38 // Bit 2 de selection du micro pas
#define pinMS3X2    39 // Bit 3 de selection du micro pas 
#define pinEnableX2 40 // Activation du driver/pilote
#define pinDirX2    41 // Direction

// Pinout Moteur rotation autour de Z
#define pinStepRotZ   6  // Signal de PAS (avancement)
#define pinMS1RotZ    42 // Bit 1 de selection du micro pas 
#define pinMS2RotZ    43 // Bit 2 de selection du micro pas
#define pinMS3RotZ    44 // Bit 3 de selection du micro pas 
#define pinEnableRotZ 45 // Activation du driver/pilote
#define pinDirRotZ    46 // Direction

// Pin commande de la pompe (reliée à la base du transistor)
#define pinPump 47

void setup()
{
  Serial.begin(9600);
  Serial.println("Test A4988");

  pinMode(pinEnableX1, OUTPUT);
  pinMode(pinStepX1, OUTPUT);
  pinMode(pinDirX1, OUTPUT);
  pinMode(pinMS1X1, OUTPUT);
  pinMode(pinMS2X1, OUTPUT);
  pinMode(pinMS3X1, OUTPUT);
  
  pinMode(pinEnableY, OUTPUT);
  pinMode(pinStepY, OUTPUT);
  pinMode(pinDirY, OUTPUT);
  pinMode(pinMS1Y, OUTPUT);
  pinMode(pinMS2Y, OUTPUT);
  pinMode(pinMS3Y, OUTPUT);
  
  pinMode(pinEnableZ, OUTPUT);
  pinMode(pinStepZ, OUTPUT);
  pinMode(pinDirZ, OUTPUT);
  pinMode(pinMS1Z, OUTPUT);
  pinMode(pinMS2Z, OUTPUT);
  pinMode(pinMS3Z, OUTPUT);

  pinMode(pinEnableX2, OUTPUT);
  pinMode(pinStepX2, OUTPUT);
  pinMode(pinDirX2, OUTPUT);
  pinMode(pinMS1X2, OUTPUT);
  pinMode(pinMS2X2, OUTPUT);
  pinMode(pinMS3X2, OUTPUT);

  pinMode(pinEnableRotZ, OUTPUT);
  pinMode(pinStepRotZ, OUTPUT);
  pinMode(pinDirRotZ, OUTPUT);
  pinMode(pinMS1RotZ, OUTPUT);
  pinMode(pinMS2RotZ, OUTPUT);
  pinMode(pinMS3RotZ, OUTPUT);

  pinMode(pinPump, OUTPUT);
}

void loop()
{
  int i = 0;
  
  //Init des sorties
  digitalWrite(pinEnableX1, LOW);  // Activation driver (logique inversée) 
  digitalWrite(pinDirX1, HIGH); // Dir = 1 <=> Sens trigonométrique
  digitalWrite(pinStepX1, LOW);  // Initialisation de la broche step
  digitalWrite(pinMS1X1, HIGH);  // Choix du micro pas (MS1..3 = 0 0 0 pour Full Step)
  digitalWrite(pinMS2X1, LOW);
  digitalWrite(pinMS3X1, LOW);
  
  digitalWrite(pinEnableY, LOW);  // Activation driver (logique inversée) 
  digitalWrite(pinDirY, HIGH); // Dir = 1 <=> Sens trigonométrique
  digitalWrite(pinStepY, LOW);  // Initialisation de la broche step
  digitalWrite(pinMS1Y, LOW);  // Choix du micro pas (MS1..3 = 0 0 0 pour Full Step)
  digitalWrite(pinMS2Y, LOW);
  digitalWrite(pinMS3Y, LOW);
  
  digitalWrite(pinEnableZ, LOW);  // Activation driver (logique inversée) 
  digitalWrite(pinDirZ, HIGH); // DirZ = 1 <=> Descendre
  digitalWrite(pinStepZ, LOW);  // Initialisation de la broche step
  digitalWrite(pinMS1Z, LOW);  // Choix du micro pas (MS1..3 = 1 0 0 pour Half Step)
  digitalWrite(pinMS2Z, LOW);
  digitalWrite(pinMS3Z, LOW);

  digitalWrite (pinPump, LOW);
  
  
  // Avance d'un quart de tour (1 tour = 200 pas) pour X et Y
  Serial.println("Tu tournes");
  for(i=0; i<200; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX1, HIGH);
    delay(10);
    digitalWrite(pinStepX1, LOW);
    delay(10);
    /*
    digitalWrite(pinStepY, HIGH);
    delay(20);
    digitalWrite(pinStepY, LOW);
    delay(20);
    */
  } 

  // Changer de direction
  digitalWrite(pinDirX1, LOW);
  delay(2000);

  // Refaire un quart de tour dans l'autre sens pour X
  Serial.println("Tu reverse tournes");
  for(i=0; i<200; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX1, HIGH);
    delay(10);
    digitalWrite(pinStepX1, LOW);
    delay(10);
  } 
/*
  // Pas de step et pas d'ordre... L'axe du moteur est donc bloqué 
  Serial.println("Axes bloquey + attendre 5 sec");
  delay(5000);

  // Tests du moteur glissière Z
  Serial.println("Tu glisses Z");
  for(i=0; i<12; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepZ, HIGH);
    delay(1000);
    digitalWrite(pinStepZ, LOW);
    delay(1000);
  }
  
  // Changement de sens
  digitalWrite(pinDirZ, LOW);
  Serial.println("Tu reverse glisses Z");
  
  for(i=0; i<12; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepZ, HIGH);
    delay(200);
    digitalWrite(pinStepZ, LOW);
    delay(200);
  }
 */
  // Déblocage de l'axe moteur
  Serial.println("Deblocage axe");
  digitalWrite(pinEnableX1, HIGH); // logique inversée
  digitalWrite(pinEnableY, HIGH); // logique inversée
  digitalWrite(pinEnableZ, HIGH); // logique inversée
  
  // Fin et blocage du programme
  Serial.println("Fin de programme");
  while(true);

}
