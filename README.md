# Envoi_de_donnees_sur_cloud_tp1
Envoi de donnees sur cloud:>>>>
Ce premier petit projet utilise un module Esp8266 (NodeMCU / ESP-12E) pour collecter les données environnementales depuis un capteur DHT11.Les mesures sont affichées sur le moniteur série et envoyées à une platforme IoT ThingSpeak pour suivi à distance. Idéal pour la surveillance simple de la température et de l'humidité dans une piéce ou un environnement domestique.

Fonctionnalités principales
-Lecture de capteur:>>>> Lit la température (°C) et l’humidité (%) depuis un DHT11.
-Connexion Wi-Fi:>>>> Connecte le module ESP8266 à un réseau Wi-Fi existant.
-Transmission de données IoT:>>>> Envoie les valeurs mesurées à ThingSpeak tous les 5 secondes.
-Affichage série:>>>> Affiche les valeurs mesurées sur le moniteur série pour vérification locale.

Matériel requis:
   Microcontrôleur
-Famille: ESP8266
-Module: ESP-12E / NodeMCU
-Fréquence d’horloge: 80 MHz
   Carte de développement
-Carte: NodeMCU ESP-12E

Périphériques et Broches:
DHT11, D2 (GPIO4), DATA	, Capteur température et humidité;;;;;;; VCC, 3.3V, Alimentation, Assurez-vous que le capteur supporte 3.3V;;;;;;; GND, GND, Masse	

Notes:
-La lecture DHT11 peut être instable pour certains capteurs, surtout les modèles bas de gamme.
-Pour une meilleure précision, un DHT22 ou BME280 est recommandé.
-Assurez-vous que votre réseau Wi-Fi est 2.4 GHz, car l’ESP8266 ne supporte pas le 5 GHz.
