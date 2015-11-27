// --- Commande d'un StepStick/Driver A4988 ----------------------
// A4988_Test.ino
//
// Commande d'un moteur pas-à-pas à l'aide d'un pilote A4988 avec
//     Arduino.
//
// Un projet www.mchobby.be (vente de kit et composant)
// Meurisse D. - Licence CC-SA-BY
//
// Un tutoriel http://mchobby.be/wiki/index.php?title=A4988


// Code couleur des NEMA 17 <-> brochage sur driver A4988 :
// Vert = 1A
// Bleu = 1B
// Noir = 2A
// Rouge = 2B


// Pinout Moteur NEMA 17 pour l'axe X
#define pinStepX   2  // Signal de PAS (avancement)
#define pinMS1X    22 // Bit 1 de selection du micro pas 
#define pinMS2X    23 // Bit 2 de selection du micro pas
#define pinMS3X    24 // Bit 3 de selection du micro pas 
#define pinEnableX 25 // Activation du driver/pilote
#define pinDirX    26 // Direction

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

void setup()
{
  Serial.begin(9600);
  Serial.println("Test A4988");

  pinMode(pinEnableX, OUTPUT);
  pinMode(pinStepX, OUTPUT);
  pinMode(pinDirX, OUTPUT);
  pinMode(pinMS1X, OUTPUT);
  pinMode(pinMS2X, OUTPUT);
  pinMode(pinMS3X, OUTPUT);
  
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
}

void loop()
{
  int i = 0;
  
  //Init des sorties
  digitalWrite(pinEnableX, LOW);  // Activation driver (logique inversée) 
  digitalWrite(pinDirX, HIGH); // Dir = 1 <=> Sens trigonométrique
  digitalWrite(pinStepX, LOW);  // Initialisation de la broche step
  digitalWrite(pinMS1X, LOW);  // Choix du micro pas (MS1..3 = 0 0 0 pour Full Step)
  digitalWrite(pinMS2X, LOW);
  digitalWrite(pinMS3X, LOW);
  
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
  
  
  // Avance d'un quart de tour (1 tour = 200 pas) pour X et Y
  Serial.println("Tu tournes");
  for(i=0; i<50; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX, HIGH);
    delay(20);
    digitalWrite(pinStepX, LOW);
    delay(20);
    
    digitalWrite(pinStepY, HIGH);
    delay(20);
    digitalWrite(pinStepY, LOW);
    delay(20);
  } 

  // Changer de direction
  digitalWrite(pinDirX, LOW);
  delay(2000);

  // Refaire un quart de tour dans l'autre sens pour X
  Serial.println("Tu reverse tournes");
  for(i=0; i<50; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX, HIGH);
    delay(10);
    digitalWrite(pinStepX, LOW);
    delay(10);
  } 

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
 
  // Déblocage de l'axe moteur
  Serial.println("Deblocage axe");
  digitalWrite(pinEnableX, HIGH); // logique inversée
  digitalWrite(pinEnableY, HIGH); // logique inversée
  digitalWrite(pinEnableZ, HIGH); // logique inversée
  
  // Fin et blocage du programme
  Serial.println("Fin de programme");
  while(true);

}
