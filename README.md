# Station d'Analyse de la Qualité de l'Air

## Description
Ce projet a pour objectif de construire une station d’analyse de la qualité de l’air capable de mesurer les particules fines de 2.5 micromètres (PM 2.5). La station utilise un capteur PMS7003 et envoie les données à une plateforme infonuagique via une API REST. La couleur d'une DEL RGB indique la qualité de l’air selon l’échelle AQHI ou US EPA AQI. Ce projet inclut également un serveur Web pour afficher les données et un débogage en temps réel via le moniteur série.

## Fonctionnalités
- **Lecture des valeurs PM 2.5** : Mesure continue des particules fines avec le capteur PMS7003.
- **Envoi des données à une API REST** : Envoi des données toutes les 2 minutes via une API REST.
- **Connexion Wi-Fi** : Connexion à un réseau Wi-Fi en mode STA et tentative de reconnexion automatique si la connexion est perdue.
- **Changement de couleur de la DEL** : La couleur de la DEL RGB change en fonction de la qualité de l’air (AQHI ou US EPA AQI).
- **Affichage des données sur un serveur Web** : 
  - Page de la qualité de l'air avec données en temps réel.
  - Page d’informations sur l’appareil, incluant le MAC ID, Device ID et les données de connexion Wi-Fi.
- **Wifi Manager** : Intégration d'un gestionnaire Wi-Fi pour configurer facilement le réseau.
- **Bluetooth** : Utilisation de Bluetooth pour configurer le Wi-Fi à distance via une application mobile.
