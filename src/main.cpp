#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

char ssid[] = "Ooredoo _S20_4EBF" ;
char pass[] = "7730C317" ;
// Configuration ThingSpeak
unsigned long myChannelNumber = 3092632;  
const char * myWriteAPIKey = "E636ZLBIAWWU5YIQ";

// Objet client WiFi et capteur DHT
WiFiClient client;
DHT dht(4, DHT11);  // Capteur sur la broche D2 (GPIO4)

// Variables pour les mesures
float temp = 0;
float hum = 0;

void setup() {
  Serial.begin(115200);
  
  // Initialisation du capteur DHT
  dht.begin();
  
  // Connexion WiFi
  Serial.println("Connexion au WiFi...");
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnecté au WiFi!");
  
  // Initialisation ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  delay(5000);  // Attente de 5 secondes entre les mesures
  
  // Lecture des valeurs du capteur
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  
  // Vérification des erreurs de lecture
  if (isnan(temp) || isnan(hum)) {  // Corrigé la condition
    Serial.println("Échec de lecture du capteur DHT!");
    return;
  }
  
  // Affichage sur le moniteur série
  Serial.print("Humidité = ");
  Serial.print(hum);
  Serial.print("% | Température = ");
  Serial.print(temp);
  Serial.println("°C");
  
  // Envoi des données à ThingSpeak
  ThingSpeak.writeField(myChannelNumber, 1, temp, myWriteAPIKey);  // Corrigé le nom de variable
  delay(16000);
  ThingSpeak.writeField(myChannelNumber, 2, hum, myWriteAPIKey);   // Corrigé le nom de variable
  
  Serial.println("Données envoyées à ThingSpeak!");
}
