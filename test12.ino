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
// Ou Acheter un StepStick A4988
//    http://mchobby.be/PrestaShop/product.php?id_product=349
//

#define pinEnableX 25 // Activation du driver/pilote
#define pinStepX   2  // Signal de PAS (avancement)
#define pinDirX    26 // Direction
#define pinMS1X    22 // Bit 1 de selection du micro pas 
#define pinMS2X    23 // Bit 2 de selection du micro pas
#define pinMS3X    24 // Bit 3 de selection du micro pas 

void setup()
{
  //Serial.begin(9600);
  //Serial.println("Test A4988");

  pinMode(pinEnableX, OUTPUT);
  pinMode(pinStepX, OUTPUT);
  pinMode(pinDirX, OUTPUT);
  pinMode(pinMS1X, OUTPUT);
  pinMode(pinMS2X, OUTPUT);
  pinMode(pinMS3X, OUTPUT);
}

void loop()
{
  int i = 0;
  
  digitalWrite(pinEnableX, LOW);  // Activation driver (logique inversée) 
  digitalWrite(pinDirX, HIGH); // Direction avant
  digitalWrite(pinStepX, LOW);  // Initialisation de la broche step
  digitalWrite(pinMS1X, HIGH);  // Choix du micro pas (MS3..1 = 0 0 0 pour Full Step)
  digitalWrite(pinMS2X, LOW);
  digitalWrite(pinMS3X, LOW);
  
  // Avance d'un quart de tour (1 tour = 200 pas)
  //Serial.println("Tu tournes");
  for(i=0; i<20; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX, HIGH);
    delay(125);
    digitalWrite(pinStepX, LOW);
    delay(125);
  } 

  // Changer de direction
  digitalWrite(pinDirX, LOW); // Direction avant
  delay(2000);

  // Refaire un quart de tour dans l'autre sens
  //Serial.println("Tu reverse tournes");
  for(i=0; i<50; i++)
  {
    //Serial.println( i );
    digitalWrite(pinStepX, HIGH);
    delay(10);
    digitalWrite(pinStepX, LOW);
    delay(10);
  } 

  // Pas de step et pas d'ordre... 
  //   l'axe du moteur est donc bloqué 
  //Serial.println("Axe bloquey + attendre 5 sec");
  delay(5000);

  // déblocage de l'axe moteur
  //Serial.println("Deblocage axe");
  digitalWrite(pinEnableX, HIGH); // logique inversée
  
  // Fin et blocage du programme
  // Presser reset pour recommander
  //Serial.println("Fin de programme");
  while( true );

}
